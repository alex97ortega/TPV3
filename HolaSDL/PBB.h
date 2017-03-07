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
	PBB(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~PBB();

	void incrX();
	void incrY();
	void onClick();
	void update();
	void draw();

	int getX() { return pimgx; }
	int getY() { return pimgy; }
	void setX(int x) { this->pimgx = x; }
	void setY(int y) { this->pimgy = y; }
	int getClicks() { return clicks; }
	void desactivate(){ explotado = true; }
	int getPoints(){ return puntos; }
	void setPoints(int p){ this->puntos = p; }
	void gainPoints(int gp){ this->puntos += gp; }
	void add(){; }
	void sub(){ ; }
	void mul(){ ; }
	void push_n(int i){ ; }
	void goto_n(int i){ ; }
	void jmpz_n(){ ; }
	void jmpgt_n(){ ; }


	JuegoPG* juegootp;

	JuegoPG::Texturas_t Ttextura;
private:

	bool explotado;
	int clicks;
	int dx, dy, puntos;
	SDL_Rect rect;
	PBBVM vm;
	PBBVMprog prog;
};

