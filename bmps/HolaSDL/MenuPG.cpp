#include "MenuPG.h"
#include "PlayPG.h"
#include "Boton.h"
#include "Config.h"

MenuPG::MenuPG(JuegoPG * juego) :EstadoPG(juego)
{
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BSalir, 450, 350, salir));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BJugar, 150, 350, play));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::TConfig, 600, 700, config));
}


MenuPG::~MenuPG()
{
}


void MenuPG::salir(JuegoPG * jg){
	jg->setSalir();
}

void MenuPG::play(JuegoPG * jg){
	jg->changeState(new PlayPG(jg));
	
}

void MenuPG::config(JuegoPG * jg){
	jg->pushState(new Config(jg));
}