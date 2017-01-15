#pragma once
#include "EstadoJuego.h"
#include "JuegoPG.h"

class EstadoPG : public EstadoJuego
{
public:
	EstadoPG(JuegoPG * juego);
	~EstadoPG();
	void draw();
	void update();
	void onClick();

protected:

	JuegoPG* ptajuego;
	
	std::vector <ObjetoJuego*> objetos;
};

