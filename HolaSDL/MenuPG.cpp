#include "MenuPG.h"
#include "PlayPG.h"

MenuPG::MenuPG(JuegoPG * juego) :EstadoPG(juego)
{
	bPlay = new Boton(juego, JuegoPG::TBoton, 400, 400, play); 
	bExit = new Boton(juego, JuegoPG::TBoton, 400, 400, salir);
}


MenuPG::~MenuPG()
{
}


void MenuPG::salir(JuegoPG * jg){
	jg->setSalir();
}

void MenuPG::play(JuegoPG * jg){
	jg->changeState(new PlayPG ()); // parametro desconosido
}