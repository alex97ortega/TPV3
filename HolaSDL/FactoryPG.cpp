#include "FactoryPG.h"
#include "Globo.h"
#include "Vago.h"
#include "Premio.h"
#include "Mariposa.h"
#include "BouncingBall.h"


FactoryPG::FactoryPG(JuegoPG* ju)
{
	jue = ju;
}


FactoryPG::~FactoryPG()
{
}

ObjetoJuego*FactoryPG::createNormalElement()
{
	return new Globo(jue, JuegoPG::Texturas_t::TGlobo, rand() % 700, rand() % 700);
}

ObjetoJuego*FactoryPG::createSpecialElement()
{
	return new Mariposa(jue, JuegoPG::Texturas_t::TMariposa, rand() % 700, rand() % 700);
	
}

ObjetoJuego*FactoryPG::createPrizeElement()
{
	return new Premio(jue, JuegoPG::Texturas_t::TPremio, rand() % 700, rand() % 700);
	
}

//llamamos a cada objeto dependiendo de su tipo en cada metodo correspondiente