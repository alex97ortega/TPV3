#pragma once
#include <vector>
#include <string>
#include "ObjetoJuego.h"
#include <SDL.h>
#include "texturasSDL.h"

class JuegoPG
{
public:
	JuegoPG();
	~JuegoPG();
	void run();


	enum Texturas_t {TFondo, TGlobo, TMariposa, TPremio};


	texturasSDL* getTextura(Texturas_t et) const { return texturas[et]; }
	SDL_Renderer* getRender() const;
	void getMousePos(int & mpx, int & mpy) const; 
	void newBaja(ObjetoJuego* po); 
	void newPuntos(ObjetoJuego* po); 
	void newPremio(); 
	void initMedia(); 
	void freeMedia();


private:

	SDL_Window * pWin  = nullptr;
	SDL_Renderer* pRender = nullptr;

	std::string ntexturas[4];

	std::vector<ObjetoJuego*> globos;

	std::vector<texturasSDL*> texturas;

	int alto = 800;
	int ancho = 800;


	int mx;
	int my;



	SDL_Color color;

	int puntos;

	int numglobos;
	int numglobosA;
	int finglobos;

	bool error;
	bool gameOver;
	bool exit;
	bool espera;//evaluacion1

	SDL_Event e;

	bool initSDL();
	void closeSDL();
	bool initGlobos();
	void freeGlobos();
	void render() const;
	void onClick(int pmx, int pmy);
	void update();
	bool handle_event();
	void onExit();
};