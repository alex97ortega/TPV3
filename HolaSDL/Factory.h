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

	virtual ObjetoJuego* createNormalElement(char tipo) = 0;
	virtual ObjetoJuego* createSpecialElement(char tipo) = 0;
	virtual ObjetoJuego* createPrizeElement(char tipo) = 0;
};