#include "Pausa.h"
#include "MenuPG.h"
#include "PlayPG.h"

Pausa::Pausa(JuegoPG * juego) : EstadoPG(juego)
{
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BContinuar, 200, 400, resume));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BMenu, 500, 400, menu));
}


Pausa::~Pausa()
{
}


void Pausa::resume(JuegoPG * jg){
	jg->popState();
}

void Pausa::menu(JuegoPG * jg){
	jg->changeState(new MenuPG(jg));
}