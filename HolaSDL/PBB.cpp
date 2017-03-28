#include "PBB.h"



PBB::PBB(JuegoPG* juego, PBBVMprog*pb, JuegoPG::Texturas_t text, int x, int y) : prog("/tmp/prog.vm")
{
	p = pb;
	juegootp = juego;
	Ttextura = text;

	pimgx = x;
	pimgy = y;

	ancho = 75;
	alto = 75;

	dx = (rand() % 6) * 10;
	dy = (rand() % 6) * 10;

	explotado = false;

	puntos = (rand() % 51) + 50;

	clicks = 0;
}


PBB::~PBB()
{
}

void PBB::draw() {
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	//si es visible llama al draw de texturasSDl
	if (!explotado) {
		SDL_Renderer* render = juegootp->getRender();
		juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	}
}



void PBB::onClick() {
	clicks ++;
}

int  PBB::getX() { 
	return dx; std::cout << "getX"; 
}

int  PBB::getY() { 
	return dy; std::cout << "getY"; 
}

void  PBB::setX(int x) { 
	dx = x; std::cout << "setX";
}

void  PBB::setY(int y) { 
	dx = y; std::cout << "setY";
}

int  PBB::getClicks() { 
	return clicks; std::cout << "getClicks"; 
}

void  PBB::desactivate(){
	explotado = true; std::cout << "desactivate"; 
}

int  PBB::getPoints(){
	return puntos; std::cout << "getPoints"; 
}

void  PBB::setPoints(int p){
	puntos = p; std::cout << "setPoints"; 
}

void  PBB::gainPoints(int gp){
	juegootp->setPuntos(gp); std::cout << "gainPoints;"; 
}




void PBB::update() {
	
	if (!explotado) {
		pimgx += dx;
		pimgy += dy;

		if (pimgx <= 0) {
			dx = -1 * dx;
			puntos -= 10;
		}

		if (pimgx >= 720) {
			dx = -1 * dx;
			puntos -= 10;
		}

		if (pimgy <= 0) {
			dy = -1 * dy;
			puntos -= 10;
		}

		if (pimgy >= 720) {
			dy = -1 * dy;
			puntos -= 10;
		}
	}
	if (puntos <= 0) explotado = true;

	// hay que hacer este mismo código pero haciendo llamadas al programa con vm.run(prog, *this);
}



