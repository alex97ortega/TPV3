#include "MenuPG.h"
#include "PlayPG.h"
#include "Boton.h"
#include "FactoryPG.h"
#include "FactoryBola.h"

MenuPG::MenuPG(JuegoPG * juego) :EstadoPG(juego)
{
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BSalir, 500, 400, salir));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BJugar, 200, 400, play));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BBola, 200, 600, playBola));

}


MenuPG::~MenuPG()
{
}


void MenuPG::salir(JuegoPG * jg){
	jg->setSalir();
}

void MenuPG::play(JuegoPG * jg){
	jg->changeState(new PlayPG(jg));  //new FactoryPG (jg);
}

void MenuPG::playBola(JuegoPG * jg){
	jg->changeState(new PlayPG(jg));
}