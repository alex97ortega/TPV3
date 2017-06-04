#pragma once
#include "PBBExternAccess.h"
#include "PBBVM.h"
#include "PBBVMprog.h"
#include "ObjetoPG.h"
#include "JuegoPG.h"

class PBB : // Programable Bouncing Ball
	public PBBExternAccess, public ObjetoPG
{
public:
	PBB(); // inicializar el programa
	PBB(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~PBB();


	bool onClick();
	void update();
	void draw();

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getClicks();
	void desactivate();
	int getPoints();
	void setPoints(int p);
	void gainPoints(int gp);

	JuegoPG* juegootp;
	JuegoPG::Texturas_t Ttextura;

private:

	int pimgx, pimgy, alto, ancho;
	bool explotado;
	int clicks;
	int dx, dy, puntos;
	SDL_Rect rect;
	PBBVMprog prog;
	static PBBVM vm;
};

