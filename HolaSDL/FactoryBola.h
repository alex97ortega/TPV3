#pragma once
#include "FactoryBola.h"
#include "Factory.h"
#include "Globo.h"
#include "Mariposa.h"
#include "Premio.h"
#include "Vago.h"
#include "BouncingBall.h"

class FactoryBola :
	public Factory
{
public:
	FactoryBola();
	~FactoryBola();
	virtual ObjetoJuego* createNormal(JuegoPG* juego, JuegoPG::Texturas_t text, int a, int b){
		return new BouncingBall(juego,text, a, b);
	}
	virtual ObjetoJuego* createSpecial(JuegoPG* juego, JuegoPG::Texturas_t text, int a, int b) {
		return new Vago();
	}
	virtual ObjetoJuego* createPrize(JuegoPG* juego, JuegoPG::Texturas_t text, int a, int b){
		return new Vago();
	}
	
};

