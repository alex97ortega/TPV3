#include "EstadoPG.h"


EstadoPG::EstadoPG(JuegoPG * juego)
{
	ptajuego = juego;

}


EstadoPG::~EstadoPG()
{
}

void EstadoPG::draw(){
	for (int i = 0; i < objetos.size() - 1; i++){
		objetos[i]->draw();
	}
}


void EstadoPG::onClick(){
	bool clickeado = false; //igual que en juegoPG

	int i = objetos.size() - 1;
	while (i >= 0 && !clickeado)
	{
		if (objetos[i]->onClick())
			clickeado = true;

		i--;
	}

}


void EstadoPG::update(){
	for (int i = 0; i < objetos.size() - 1; i++){
		objetos[i]->update();
	}
}