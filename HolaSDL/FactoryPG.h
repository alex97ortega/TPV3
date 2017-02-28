#pragma once
#include "Factory.h"
#include "Globo.h"
#include "Mariposa.h"
#include "Premio.h"
#include "Vago.h"


class FactoryPG :
	public Factory
{
public:
	FactoryPG();
	~FactoryPG();

	virtual ObjetoJuego* createNormal(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int d){
		return new Globo(juego, text, x, d);
	}
	virtual ObjetoJuego* createSpecial(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int d) {
		return new Mariposa(juego, text, x, d);
	}
	virtual ObjetoJuego* createPrize(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int d){
		return new Premio(juego, text, x, d);
	}
};

