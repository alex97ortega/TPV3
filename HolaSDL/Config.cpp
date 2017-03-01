#include "Config.h"
#include "MenuPG.h"
#include "FactoryBola.h"
#include "FactoryPG.h"


Config::Config(JuegoPG * juego) : EstadoPG(juego)
{
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BBall, 500, 400, ball));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BNormal, 200, 400, normal));
}


Config::~Config()
{
}

//dependiendo de lo que elijas cambia el puntero
void Config::ball(JuegoPG * jg){
	jg->changeFac('b');
	jg->changeState(new MenuPG(jg));
}


void Config::normal(JuegoPG * jg){
	jg->changeFac('g');
	jg->changeState(new MenuPG(jg));
}

