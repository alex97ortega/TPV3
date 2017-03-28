#pragma once
#include "PBBExternAccess.h"
#include "PBBVM.h"
#include "PBBVMprog.h"

#include "JuegoPG.h"

class PBB : // Programable Bouncing Ball
	public PBBExternAccess
{
public:
	PBB(); // inicializar el programa
	PBB(JuegoPG* juego, PBBVMprog*p, JuegoPG::Texturas_t text, int x, int y);
	~PBB();


	void onClick();
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
	PBBVMprog*p;

	JuegoPG::Texturas_t Ttextura;
private:

	bool explotado;
	int clicks;
	int dx, dy, puntos;
	SDL_Rect rect;
	PBBVM vm;
	PBBVMprog prog;
};

