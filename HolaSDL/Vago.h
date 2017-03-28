#pragma once
#include "ObjetoPG.h"
class Vago : public ObjetoPG
{
public:
	Vago(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~Vago();
	void draw();
	bool onClick();
	void update();

};

//clase auxiliar