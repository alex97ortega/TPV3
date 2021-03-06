#include "JuegoPG.h"
#include "Globo.h"
#include "GloboA.h"
#include "Mariposa.h"
#include "Premio.h"
#include "SDLError.h"
#include "PlayPG.h"
#include "Pausa.h"
#include "MenuPG.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include "FactoryBola.h"
#include "FactoryPG.h"



JuegoPG::JuegoPG()
{  
	//array de ntexturas
	ntexturas[0] = "../bmps/fondo.png";
	ntexturas[1] = "../bmps/globo.png";
	ntexturas[2] = "../bmps/mariposa.png";
	ntexturas[3] = "../bmps/premio.png";
	ntexturas[4] = "../bmps/buttonContinuar.png";
	ntexturas[5] = "../bmps/buttonJugar.png";
	ntexturas[6] = "../bmps/buttonMenu.png";
	ntexturas[7] = "../bmps/buttonSalir.png";
	ntexturas[8] = "../bmps/buttonScore.png";
	ntexturas[9] = "../bmps/bola.png";
	ntexturas[10] = "../bmps/config.png";
	ntexturas[11] = "../bmps/normal.png";
	ntexturas[12] = "../bmps/BalGame.png";

	srand(SDL_GetTicks());

	gameOver = false;
	
	exit = false;
	espera = false;
	puntos = 0;

	initSDL();
	initMedia();

	Estados.push(new MenuPG(this));

	fac = new FactoryBola(this);

}


JuegoPG::~JuegoPG()
{
	freeMedia();
	closeSDL();
	pWin = nullptr;
	pRender = nullptr;
	while (!Estados.empty()){
		popState();
	}
}

SDL_Renderer* JuegoPG::getRender()const{
	return pRender;
}

void JuegoPG::getMousePos(int & mpx, int & mpy) const{ //obtener posicion del mouse
	mpx = mx;
	mpy = my;
}


void JuegoPG::initMedia(){

	for (int i = 0; i < 13; i++){
		//cargar todo tipo de texturas
		texturas.emplace_back(new texturasSDL);
		texturas[i]->load(getRender(), ntexturas[i]);

	}
}

void JuegoPG::freeMedia(){
	//borramos las texturas y hacemos el puntero nulo
	for (int i = 0; i < texturas.size(); i++){
		delete texturas[i];
		texturas[i] = nullptr;
	}
}




void JuegoPG::run(){ 

	Uint32 MSxUpdate = 500;
	std::cout << "PLAY \n";
	Uint32 lastUpdate = SDL_GetTicks();
	render();
	espera = handle_event();
	while (!exit && !gameOver) {
		if ((SDL_GetTicks() - lastUpdate) >= MSxUpdate && !espera) { // while(elapsed >= MSxUpdate)
			update();
			lastUpdate = SDL_GetTicks();
		}
		render();
		espera = handle_event();
	}
	if (exit)
		std::cout << "EXIT \n";
	else {//para que aparezca la ventana final con la puntuacion
		std::cout << "Has obtenido " << puntos << " puntos\n";
		std::string spuntos = "HAS OBTENIDO " + std::to_string(puntos) + " PUNTOS";
		char const *cpuntos = spuntos.c_str();

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "END GAME", cpuntos, nullptr);
	}
	SDL_Delay(1000);
	//std::cin.get();

}


bool JuegoPG::initSDL() {


	bool success = true; //Initialization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw SDLError("SDL could not initialize!");///////

		std::cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		//le paso el tama�o que quiero que tenga la ventana de mi juego
		pWin = SDL_CreateWindow("SDL Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, alto, ancho, SDL_WINDOW_SHOWN);
		if (pWin == nullptr){
			throw SDLError("Window could not be created!");///////////////

			std::cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWin, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRender, color.r, color.g, color.b, color.a); //Set background color to black 
			if (pRender == nullptr){
				throw SDLError("Renderer could not be created!");//////Puedes hacer un error especial para render

				std::cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}

//para destruir la ventana el render y cerrarla
void JuegoPG::closeSDL() {
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;

	SDL_DestroyWindow(pWin);
	pWin = nullptr;

	SDL_Quit();
}



void JuegoPG::render(){ //llama render de el estado en el que estemos
	//limpiamos el render
	SDL_RenderClear(pRender);

	//fondo
	texturas[0]->draw(pRender, nullptr, nullptr);

	topEstado()->draw();
	SDL_RenderPresent(pRender);
}


void JuegoPG::onClick(int pmx, int pmy){ //llama onclick del estado en el que estemos
	mx = e.button.x;
	my = e.button.y;
	topEstado()->onClick();
}

void JuegoPG::update(){ //llama update del estado en el que estemos
	mx = e.button.x;
	
	topEstado()->update();
}


bool JuegoPG::handle_event(){ //eventos del teclado y rat�n
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT){
			exit = true;
			std::cout << "QUIT";
		}
		else if (e.type == SDL_KEYUP){
			if (e.key.keysym.sym = SDLK_ESCAPE){
				pushState(new Pausa(this));
				std::cout << "PAUSE \n";
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP) { // click izquierdo para llamar al onclick
			if (e.button.button == SDL_BUTTON_LEFT) {
				std::cout <<puntos << " CLICK \n";
				onClick(e.button.x, e.button.y);
				
			}
		}
	}

	return espera;
}


EstadoJuego * JuegoPG::topEstado(){//devuelve el estado
	return Estados.top();
}

void JuegoPG::changeState(EstadoJuego* newSt){//cambia el estado
		popState();
		pushState(newSt);
}


void JuegoPG::pushState(EstadoJuego* newState){//a�ade como ultimo estado
	Estados.push(newState);
}


void JuegoPG::popState(){//quita el ultimo estado
	delete Estados.top();
	Estados.pop();
}


void JuegoPG::setSalir(){//sale
	exit = true;
	closeSDL();
	
}

void JuegoPG::darPuntos(int i){
	puntos = i;
}

int JuegoPG::damePuntos(){
	return puntos;
}

void JuegoPG::changeFac(char y){//dependiendo de lo que elijas
	if (y == 'b')
		fac = new FactoryBola(this);
	else
		fac = new FactoryPG(this);
}

Factory* JuegoPG::dame(){ //devuelve la factoria
	return fac;
}
