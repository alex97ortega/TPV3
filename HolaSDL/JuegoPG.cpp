#include "JuegoPG.h"
#include "Globo.h"
#include "GloboA.h"
#include "Mariposa.h"
#include "Premio.h"
#include "SDLError.h"
#include "PlayPG.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>



JuegoPG::JuegoPG()
{  
	//array de ntexturas
	ntexturas[0] = "../bmps/fondo.png";
	ntexturas[1] = "../bmps/globo.png";
	ntexturas[2] = "../bmps/mariposa.png";
	ntexturas[3] = "../bmps/premio.png";
	ntexturas[4] = "../bmps/button.png";

	srand(SDL_GetTicks());

	/*numglobos = 3; // evaluacion 
	numglobosA = 3;
	finglobos = 7;
	
	error = false;*/
	gameOver = false;
	
	exit = false;
	espera = false;

	initSDL();
	initMedia();
	//initGlobos();

	Estados.push(new PlayPG(this));

}


JuegoPG::~JuegoPG()
{
	freeMedia();
	//freeGlobos();
	closeSDL();
	pWin = nullptr;
	pRender = nullptr;
}

SDL_Renderer* JuegoPG::getRender()const{
	return pRender;
}

void JuegoPG::getMousePos(int & mpx, int & mpy) const{ //obtener posicion del mouse
	mpx = mx;
	mpy = my;
}

/*void JuegoPG::newBaja(ObjetoJuego* po){//cada vez que se rompe un globo 
	finglobos--;
}

void JuegoPG::newPuntos(ObjetoJuego* po){// los puntos tanto de globos como de premio
	if (typeid(*po) == typeid(Globo))
		puntos += dynamic_cast<Globo*>(po)->damePuntos();
	if (typeid(*po) == typeid(Premio))
		puntos += dynamic_cast<Premio*>(po)->damePuntos();
}

void JuegoPG::newPremio(){//llamamos al reinicia 
	dynamic_cast<Premio*>(globos[4])->reiniciaPremio();

}*/

void JuegoPG::initMedia(){

	//cargar todo tipo de texturas
		texturas.emplace_back(new texturasSDL);
		texturas[0]->load(getRender(), ntexturas[0]);

		texturas.emplace_back(new texturasSDL);
		texturas[1]->load(getRender(), ntexturas[1]);

		texturas.emplace_back(new texturasSDL);
		texturas[2]->load(getRender(), ntexturas[2]);

		texturas.emplace_back(new texturasSDL);
		texturas[3]->load(getRender(), ntexturas[3]);

		texturas.emplace_back(new texturasSDL);
		texturas[4]->load(getRender(), ntexturas[4]);
}

void JuegoPG::freeMedia(){
	//borramos las texturas y hacemos el puntero nulo
	for (int i = 0; i < texturas.size(); i++){
		delete texturas[i];
		texturas[i] = nullptr;
	}
}




void JuegoPG::run(){ 

	Uint32 MSxUpdate = 500; // VELOCIDAD DE LA PARTIDA
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
		//le paso el tamaño que quiero que tenga la ventana de mi juego
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

/*bool JuegoPG::initGlobos(){
	int x = rand() % 2; // entre 0 y 1
	//globos.emplace_back(new Globo(this, TGlobo, //rand() % 700, rand() % 700 alto / 2, ancho / 2)); //evaluacion1

	
	//for (int i = 0; i < numglobos; i++) { // aleatorio punto 2
		//if (x == 0)
		//  globos.emplace_back(new Globo(this, TGlobo, rand() % 700, rand() % 700)); 
		//else 
	    //  globos.emplace_back(new GloboA(this, TGlobo, rand() % 700, rand() % 700));
	//}
	
	globos.emplace_back(new Globo(this, TGlobo, rand() % 700, rand() % 700));
	globos.emplace_back(new Globo(this, TGlobo, rand() % 700, rand() % 700));
	globos.emplace_back(new GloboA(this, TGlobo, rand() % 700, rand() % 700));
	globos.emplace_back(new GloboA(this, TGlobo, rand() % 700, rand() % 700));// punto 3 dos de cada tipo
	
	globos.emplace_back(new Premio(this, TPremio, rand() % 700, rand() % 700));
	//globos.emplace_back(new Premio(this, TPremio, rand() % 700, rand() % 700));

	globos.emplace_back(new Mariposa(this, TMariposa, rand() % 700, rand() % 700));
	globos.emplace_back(new Mariposa(this, TMariposa, rand() % 700, rand() % 700));



	return true;
}*/

/*void JuegoPG::freeGlobos(){
	// lo mismo que en las texturas, borramos los globos y hacemos nulo el puntero
	// en la práctica 2, este array no sólo tiene globos, asi que con el método son destruidos 
	// todos los objetos
	
	for (int i = 0; i < globos.size(); i++){
		delete globos[i];
		globos[i] = nullptr;

	}
	for (int i = 0; i < globos.size(); i++){
		delete globos[i];
		globos[i] = nullptr;

	}
}*/


void JuegoPG::render(){ //const
	//limpiamos el render
	SDL_RenderClear(pRender);

	//fondo
	texturas[0]->draw(pRender, nullptr, nullptr);

	//globos, mariposa y premio
	/*for (int i = 0; i < globos.size(); i++)
		globos[i]->draw();*/
	topEstado()->draw();
	SDL_RenderPresent(pRender);
}


void JuegoPG::onClick(int pmx, int pmy){ //se guardan las posiciones que pasan por parámetro
	mx = e.button.x;
	my = e.button.y;
	topEstado()->onClick();
	/*mx = pmx;
	my = pmy;

	bool pinchado = false;
	int i = 0;
	int n = globos.size() - 1;
	while (!pinchado && i <= n){//evaluacion 1
		if (globos[n]->onClick()){
			pinchado = true;
		}
		n--;
	}*/
}

void JuegoPG::update(){ //el juego corre mientras existan globos en el juego (aunque puede ser pausado)
	/*if (finglobos != 0){
		for (int i = 0; i < globos.size(); i++){
			globos[i]->update();
		}
	}
	else 
		gameOver = true;*/
	topEstado()->update();
}


bool JuegoPG::handle_event(){ //eventos del teclado y ratón
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT){
			exit = true;
			std::cout << "QUIT";
		}
		else if (e.type == SDL_KEYUP){//evaluacion1 (p para pausar)
			if (e.key.keysym.sym = SDLK_p && !espera){
				espera = true;
				std::cout << "PAUSE \n";
			}
			else if (e.key.keysym.sym = SDLK_p && espera){
				espera = false;
				std::cout << "CONTINUE \n";
			}

		}
		else if (e.type == SDL_MOUSEBUTTONUP) { // click izquierdo para llamar al onclick
			if (e.button.button == SDL_BUTTON_LEFT) {
				//puntos = static_cast<PlayPG*>(ptestados)->dameP(); es otro puntero, a saber cual, ya si eso ya...
				std::cout <<puntos << " CLICK \n";
				onClick(e.button.x, e.button.y);
				
			}
		}
	}

	return espera;
}


EstadoJuego * JuegoPG::topEstado(){
	return Estados.top();
}

void JuegoPG::changeState(EstadoJuego* newSt){
	/*if (newSt != pause){
		popState();
		pushState(newSt);
	}
	else*/
		pushState(newSt);
}


void JuegoPG::pushState(EstadoJuego* newState){
	Estados.push(newState);
}


void JuegoPG::popState(){
	delete Estados.top();
	Estados.pop();
}


void JuegoPG::setSalir(){
	closeSDL();
}

