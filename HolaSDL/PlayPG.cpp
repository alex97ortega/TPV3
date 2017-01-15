#include "PlayPG.h"
#include "Globo.h"
#include "GloboA.h"
#include "Premio.h"
#include "Mariposa.h"

PlayPG::PlayPG(JuegoPG * juego) : EstadoPG(juego) //el juego por parametro se lo pasas a la constructora que hemos declarado para que se lo pusiera a ptajuego(no es necesario hacerlo aqui)
{
	numglobos = 3;
	numglobosA = 3;
	finglobos = 6;
	gameOver = false;
	puntos = 0;

}


PlayPG::~PlayPG()
{
}

void PlayPG::newBaja(ObjetoJuego* po){
	if (typeid(*po) == typeid(Globo) || typeid(*po) == typeid(GloboA))
		finglobos--;
}

void PlayPG::newPuntos(ObjetoJuego* po){
	if (typeid(*po) == typeid(Globo))
		puntos += dynamic_cast<Globo*>(po)->damePuntos();
	if (typeid(*po) == typeid(Premio))
		puntos += dynamic_cast<Premio*>(po)->damePuntos();
}

void PlayPG::newPremio(){
	dynamic_cast<Premio*>(objetos[4])->reiniciaPremio();
}


void PlayPG::run(){

	Uint32 MSxUpdate = 500; 
	std::cout << "PLAY \n";
	Uint32 lastUpdate = SDL_GetTicks();
	draw();//antiguo render
	//espera = handle_event();
	while (!exit && !gameOver) {
		if ((SDL_GetTicks() - lastUpdate) >= MSxUpdate/* && !espera*/) { // while(elapsed >= MSxUpdate)
			update();
			lastUpdate = SDL_GetTicks();
		}
		draw();
		//espera = handle_event();
	}
	/*if (exit)
		std::cout << "EXIT \n";
	else {//para que aparezca la ventana final con la puntuacion
		std::cout << "Has obtenido " << puntos << " puntos\n";
		std::string spuntos = "HAS OBTENIDO " + std::to_string(puntos) + " PUNTOS";//////////////////////////////
		char const *cpuntos = spuntos.c_str();

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "END GAME", cpuntos, nullptr);
	}*/
	SDL_Delay(1000);
	//std::cin.get();

}


bool PlayPG::initGlobos(){
	int x = rand() % 2; // entre 0 y 1
	//globos.emplace_back(new Globo(this, TGlobo, /*rand() % 700, rand() % 700*/alto / 2, ancho / 2)); //evaluacion1

	
	for (int i = 0; i < numglobos; i++) { // aleatorio punto 2
		if (x == 0)
			objetos.emplace_back(new Globo(ptajuego, JuegoPG::TGlobo, rand() % 700, rand() % 700));
		else
			objetos.emplace_back(new GloboA(ptajuego, JuegoPG::TGlobo, rand() % 700, rand() % 700));
	}
	
	/*globos.emplace_back(new Globo(this, TGlobo, rand() % 700, rand() % 700));
	globos.emplace_back(new Globo(this, TGlobo, rand() % 700, rand() % 700));
	globos.emplace_back(new GloboA(this, TGlobo, rand() % 700, rand() % 700));
	globos.emplace_back(new GloboA(this, TGlobo, rand() % 700, rand() % 700));// punto 3 dos de cada tipo*/

	objetos.emplace_back(new Premio(ptajuego, JuegoPG::TPremio, rand() % 700, rand() % 700));

	objetos.emplace_back(new Mariposa(ptajuego, JuegoPG::TMariposa, rand() % 700, rand() % 700));
	objetos.emplace_back(new Mariposa(ptajuego, JuegoPG::TMariposa, rand() % 700, rand() % 700));



	return true;
}

void PlayPG::freeGlobos(){
	// lo mismo que en las texturas, borramos los globos y hacemos nulo el puntero
	// en la práctica 2, este array no sólo tiene globos, asi que con el método son destruidos 
	// todos los objetos

	for (int i = 0; i < objetos.size(); i++){
		delete objetos[i];
		objetos[i] = nullptr;

	}
	for (int i = 0; i < objetos.size(); i++){
		delete objetos[i];
		objetos[i] = nullptr;

	}
}