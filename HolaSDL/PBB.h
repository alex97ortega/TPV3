#pragma once
#include "PBBExternAccess.h"
#include "PBBVM.h"
#include "PBBVMprog.h"

#include "JuegoPG.h"

class PBB : // Programable Bouncing Ball
	public PBBExternAccess
{
public:
	PBB() : prog("/tmp/prog.vm") { ; } // inicializar el programa
	PBB(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~PBB();

	void incrX();
	void incrY();
	void onClick();
	void update();
	void draw();

	int getX() {return pimgx;}
	int getY() {return pimgy;}
	void setX(int x) {this->pimgx = x;} 
	void setY(int y) {this->pimgy = y;}

	JuegoPG* juegootp;

	JuegoPG::Texturas_t Ttextura;
private:
	bool explotado;
	int dx, dy, puntos;
	SDL_Rect rect;
	PBBVM vm;
	PBBVMprog prog;
};

