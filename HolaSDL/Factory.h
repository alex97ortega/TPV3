#pragma once
#include "ObjetoJuego.h"

class Factory
{
public:

	Factory()
	{
	}

	virtual ~Factory()
	{
	}

	virtual ObjetoJuego* createNormalElement() = 0;
	virtual ObjetoJuego* createSpecialElement() = 0;
	virtual ObjetoJuego* createPrizeElement() = 0;	JuegoPG* juegofact;
};