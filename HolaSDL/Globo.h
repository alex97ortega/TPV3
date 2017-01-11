#pragma once
#include "ObjetoPG.h"

class Globo : public ObjetoPG
{
public:
	Globo(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~Globo();
	virtual void draw();
	bool onClick();
	void update();
	virtual int damePuntos(); // virtual para ejercicios

private:


	bool visible;
	bool explotado;

	int mx;
	int my;


	SDL_Rect rect;

	int puntos = 1;

	//constantes del juego
	static const int PVIS = 70;
	static const int PDES = 30;
	static const int DT = 5;
	static const int AP = 5;
};

