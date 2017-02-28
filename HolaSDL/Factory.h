#pragma once
#include "ObjetoJuego.h"
#include "JuegoPG.h"

class Factory
{
public:

	Factory()
	{
	}

	virtual ~Factory()
	{
	}

	virtual ObjetoJuego* createNormal(JuegoPG* juego, JuegoPG::Texturas_t text, int a, int b) = 0;
	virtual ObjetoJuego* createSpecial(JuegoPG* juego, JuegoPG::Texturas_t text, int a, int b) = 0;
	virtual ObjetoJuego* createPrize(JuegoPG* juego, JuegoPG::Texturas_t text, int a, int b) = 0;	
};
