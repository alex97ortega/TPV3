#pragma once
#include "EstadoPG.h"

class PlayPG: public EstadoPG
{
public:
	PlayPG(JuegoPG * juego);
	~PlayPG();

	void run();
	void newBaja(ObjetoJuego* po); 
	void newPuntos(ObjetoJuego* po); 
	void newPremio(); 
	

private:
	int numglobos;
	int numglobosA;
	int finglobos;
	int puntos;
	bool gameOver;
	bool initGlobos();
	void freeGlobos();
};

