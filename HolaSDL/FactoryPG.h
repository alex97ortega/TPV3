#pragma once
#include "Factory.h"
class FactoryPG :
	public Factory
{
public:
	FactoryPG(JuegoPG * juego);
	~FactoryPG();

	ObjetoJuego* createNormalElement();
	ObjetoJuego* createSpecialElement();
	ObjetoJuego* createPrizeElement();

};

