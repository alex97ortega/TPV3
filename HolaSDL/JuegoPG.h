#pragma once
#include <vector>
#include <string>
#include "ObjetoJuego.h"
#include <SDL.h>
#include "texturasSDL.h"
#include "EstadoJuego.h"
#include <stack>

class JuegoPG
{
public:
	JuegoPG();
	~JuegoPG();
	void run();


	enum Texturas_t {TFondo, TGlobo, TMariposa, TPremio, TBoton};


	texturasSDL* getTextura(Texturas_t et) const { return texturas[et]; }
	SDL_Renderer* getRender() const;
	void getMousePos(int & mpx, int & mpy) const; 
	//void newBaja(ObjetoJuego* po); 
	//void newPuntos(ObjetoJuego* po); 
	//void newPremio(); 
	void initMedia(); 
	void freeMedia();

	int puntos;


	EstadoJuego* topEstado();
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	void setSalir();
	

private:

	SDL_Window * pWin  = nullptr;
	SDL_Renderer* pRender = nullptr;

	std::string ntexturas[5];

	//std::vector<ObjetoJuego*> globos;//no solo globos tambien premio...

	std::vector<texturasSDL*> texturas;

	int alto = 800;
	int ancho = 800;


	int mx;
	int my;



	SDL_Color color;


	//int numglobos;
	//int numglobosA;
	//int finglobos;

	bool error;
	bool gameOver;
	bool exit;
	bool espera;//evaluacion1

	SDL_Event e;

	bool initSDL();
	void closeSDL();
	//bool initGlobos();
	//void freeGlobos();
	void render(); //const
	void onClick(int pmx, int pmy);
	void update();
	bool handle_event();
	void onExit();

	std::stack<EstadoJuego*> Estados; 

	EstadoJuego * ptestados;
};