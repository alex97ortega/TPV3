#pragma once
#include "Factory.h"
#include "JuegoPG.h"

class FactoryPG :
	public Factory
{
public:

	FactoryPG(JuegoPG* ju);
	~FactoryPG();

	JuegoPG * jue;
	ObjetoJuego* createNormalElement();
	ObjetoJuego* createSpecialElement();
	ObjetoJuego* createPrizeElement();
};

//declaramos un puntero a juego y los metodos