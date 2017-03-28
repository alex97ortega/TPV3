#pragma once
#include "ObjetoPG.h"

class BouncingBall : public ObjetoPG
{
public:
	BouncingBall(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~BouncingBall();

	void draw();
	bool onClick();
	void update();

private:
	bool explotado;

	int mx;
	int my;

	int dx;
	int dy;

	SDL_Rect rect;

};

//