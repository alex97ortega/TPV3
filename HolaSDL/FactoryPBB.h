#pragma once
#include "Factory.h"
#include "JuegoPG.h"

class FactoryPBB : public Factory
{
public:
	FactoryPBB(JuegoPG * j);
	~FactoryPBB();

	ObjetoJuego* createPBB();
	ObjetoJuego* createSpecialElement();
	ObjetoJuego* createPrizeElement();
	JuegoPG * jue;
};

