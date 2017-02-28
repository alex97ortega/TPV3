#include "FactoryBola.h"


FactoryBola::FactoryBola(JuegoPG * juego)
{
	juegofact = juego;
}


FactoryBola::~FactoryBola()
{
}


ObjetoJuego*Factory::createNormalElement()
{
	return new BouncingBall(juegofact, JuegoPG::TGlobo, rand() % 700, rand() % 700);
	return new Vago();
}

ObjetoJuego*Factory::createSpecialElement()
{
	return new Vago();
}

ObjetoJuego*Factory::createPrizeElement()
{
	return new Vago();
}
