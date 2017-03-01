#include "Vago.h"


Vago::Vago(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y)
{
	juegootp = juego;
	Ttextura = text;
	pimgx = x;
	pimgy = y;
}


Vago::~Vago()
{
}


void Vago::draw(){

}
bool Vago::onClick(){
	return false;// retornamos false ya que si retornamos true lo toma como el onclik de las bolas
}

void Vago::update(){

}

