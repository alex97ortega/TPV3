#include "FactoryPG.h"
#include "Factory.h"
#include "Globo.h"
#include "Mariposa.h"
#include "Premio.h"
#include "Vago.h"



FactoryPG::FactoryPG(JuegoPG * juego)
{
	juegofact = juego;
}


FactoryPG::~FactoryPG()
{
}

ObjetoJuego*FactoryPG::createNormalElement()
{
	return new Globo(juegofact, JuegoPG::TGlobo, rand() % 700, rand() % 700);
	return new Vago();
}

ObjetoJuego*FactoryPG::createSpecialElement()
{
	return new Mariposa(juegofact, JuegoPG::TMariposa, rand() % 700, rand() % 700);
}

ObjetoJuego*FactoryPG::createPrizeElement()
{
	return new Premio(juegofact, JuegoPG::TPremio, rand() % 700, rand() % 700);
}
	