#include "BouncingBall.h"
#include "PlayPG.h"

BouncingBall::BouncingBall(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y)
{
	juegootp = juego;//lo mismo de globos
	Ttextura = text;

	pimgx = x;
	pimgy = y;

	ancho = 75;
	alto = 75;

	dx = (rand() % 6) * 10;///direccion de la pelota, puede ser mas random si queremos
	dy = (rand() % 6) * 10;

	visible = true;
	explotado = false;

	puntos = (rand() % 51) * 2;
}


BouncingBall::~BouncingBall()
{
}


void BouncingBall::draw(){// same globos
	rect.h = alto;
	rect.w = ancho;
	rect.x = pimgx;
	rect.y = pimgy;

	//si es visible llama al draw de texturasSDl
	if (visible && !explotado){
		SDL_Renderer* render = juegootp->getRender();
		juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);
	}

}


void BouncingBall::update(){
	pimgx += dx;
	pimgy += dy;

	if (pimgx <= 0){
		dx = -1 * dx;
		puntos -= 10;
	}

	if (pimgx >= 720){
		dx = -1 * dx;
		puntos -= 10;
	}

	if (pimgy <= 0){
		dy = -1 * dy;
		puntos -= 10;
	}

	if (pimgy >= 720){
		dy = -1 * dy;
		puntos -= 10;
	}
}


bool BouncingBall::onClick(){
	juegootp->getMousePos(mx, my);
	if (visible && !explotado){
		if (dentro(mx, my)){
			explotado = true;
			dynamic_cast<PlayPG*>(juegootp->topEstado())->newBaja(this);
			dynamic_cast<PlayPG*>(juegootp->topEstado())->newPuntos(this);
		}
		return (dentro(mx, my));
	}
	else
		return false;
}

