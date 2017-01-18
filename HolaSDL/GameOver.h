#pragma once
#include "EstadoPG.h"
#include "Boton.h"


class GameOver: public EstadoPG
{
public:
	GameOver(JuegoPG * juego);
	~GameOver();

	static void score(JuegoPG * jg);
	static void menu(JuegoPG * jg);

private:
	Boton* bScore;
	Boton* bMenu;
};
