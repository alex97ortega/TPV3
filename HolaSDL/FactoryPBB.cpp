#include "FactoryPBB.h"
#include "PBB.h"
#include "Vago.h"

FactoryPBB::FactoryPBB(JuegoPG* j)
{
	jue = j;
}


FactoryPBB::~FactoryPBB()
{
}
ObjetoJuego*FactoryPBB::createPBB()
{
	return new Vago(jue, JuegoPG::Texturas_t::TBola, rand() % 700, rand() % 700); // crear PBB omg
}

ObjetoJuego*FactoryPBB::createSpecialElement()
{
	return new Vago(jue, JuegoPG::Texturas_t::TConfig, 0, 0);
}

ObjetoJuego*FactoryPBB::createPrizeElement()
{
	return new Vago(jue, JuegoPG::Texturas_t::TConfig, 0, 0);
}