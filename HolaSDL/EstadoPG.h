#pragma once
#include "EstadoJuego.h"
#include "JuegoPG.h"

class EstadoPG : public EstadoJuego
{
public:
	EstadoPG();
	~EstadoPG();

protected:

	JuegoPG* ptajuego;
	//vector de objetos, ...
	//implementa utilidades para las subclases(MenuP, PlayPG, GameOver y Pausa)
};

