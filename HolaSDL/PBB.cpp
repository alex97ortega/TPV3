#include "PBB.h"



PBB::PBB(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;

	pimgx = x;
	pimgy = y;

	ancho = 75;
	alto = 75;

	dx = (rand() % 6) * 10;
	dy = (rand() % 6) * 10;

	explotado = false;

	puntos = (rand() % 51) * 2;
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

void PBB::incrX() { 
	dx ++; 
}

void PBB::incrY() {
	dy ++;
}

void PBB::onClick() {
	puntos ++;
	//llamar máquina virtual
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

