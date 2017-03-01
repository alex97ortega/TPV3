#pragma once
#include "EstadoPG.h"
#include "Boton.h"

class Config : public EstadoPG
{
public:
	Config(JuegoPG * juego);
	~Config();

	static void normal(JuegoPG * jg);
	static void ball(JuegoPG * jg);
};

//configurar el juego