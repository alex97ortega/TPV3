#include "FactoryBola.h"
#include "BouncingBall.h"
#include "Vago.h"



FactoryBola::FactoryBola(JuegoPG* ju )
{
	jue = ju;
}


FactoryBola::~FactoryBola()
{
}


ObjetoJuego*FactoryBola::createNormalElement()
{
	return new BouncingBall(jue, JuegoPG::Texturas_t::TBola, rand() % 700, rand() % 700);
}

ObjetoJuego*FactoryBola::createSpecialElement()
{
	return new Vago(jue, JuegoPG::Texturas_t::TConfig, 0, 0);
}

ObjetoJuego*FactoryBola::createPrizeElement()
{
	return new Vago(jue, JuegoPG::Texturas_t::TConfig, 0, 0);
}

//llamamos a cada objeto dependiendo de su tipo en cada metodo correspondiente