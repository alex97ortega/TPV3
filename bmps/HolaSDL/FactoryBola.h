#pragma once
#include "Factory.h"
#include "JuegoPG.h"

class FactoryBola : public Factory
{
public:
	FactoryBola(JuegoPG * ju);
	~FactoryBola();

	JuegoPG * jue;
	ObjetoJuego* createNormalElement();
	ObjetoJuego* createSpecialElement();
	ObjetoJuego* createPrizeElement();
};

//declaramos un puntero a juego y los metodos