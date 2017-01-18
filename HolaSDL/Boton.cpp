#include "Boton.h"


Boton::Boton(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y, CallBack_t * cbCons)
{
	juegootp = juego;

	pimgx = x;
	pimgy = y;

	Ttextura = text;

	cb = cbCons;
}


Boton::~Boton()
{
}

void Boton::draw(){
	rectb.h = alto;
	rectb.w = ancho;
	rectb.x = pimgx;
	rectb.y = pimgy;

	juegootp->getTextura(Ttextura)->draw(juegootp->getRender(), nullptr, &rectb);
	
}

bool Boton::onClick(){
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)){
		cb(juegootp);
	}
	else
		return(dentro(mpbx, mpby));
}
