#pragma once
#include "ObjetoPG.h"

class Premio : public ObjetoPG
{
public:
	Premio(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~Premio();
	void draw();
	bool onClick();
	void update();
	int damePuntos();
	void reiniciaPremio();

private:

	int mx;
	int my;

	int puntos = 200;

	int cont = 3;

	bool visible;


	SDL_Rect rect;
};