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

	void incrX();
	void incrY();
	void onClick();
	void update();
	void draw();

	int getX() { return pimgx; std::cout << "getX"; }
	int getY() { return pimgy; std::cout << "getY"; }
	void setX(int x) { this->pimgx = x; std::cout << "setX"; }
	void setY(int y) { this->pimgy = y; std::cout << "setY"; }
	int getClicks() { return clicks; std::cout << "getClicks"; }
	void desactivate(){ explotado = true; std::cout << "desactivate"; }
	int getPoints(){ return puntos; std::cout << "getPoints"; }
	void setPoints(int p){ this->puntos = p; std::cout << "setPoints"; }
	void gainPoints(int gp){ this->puntos += gp; std::cout << "gainPoints;"; }

	void add(){ ; std::cout << "add"; }
	void sub(){ ; std::cout << "sub"; }
	void mul(){ ; std::cout << "mul"; }
	void push_n(int i){ p->pila.push(i); std::cout << "push" + i; }
	void goto_n(int i){ ; std::cout << "goto" + i; }
	void jmpz_n(){ ; std::cout << "jmpz"; }
	void jmpgt_n(){ ; std::cout << "jmpgt"; }


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

