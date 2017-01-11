// Victor Emiliano Fernández Rubio
// Alejandro Ortega Álvarez
#include "SDL.h" 
#include "JuegoPG.h"
#include "ObjetoJuego.h"
#include "texturasSDL.h"
#include <iostream>  
int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);// para mostrar la basura 
	JuegoPG juego;
	//mostramos una ventana para empezar el juego y llamamos al metodo run
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "PLAY GAME", "Ready ? ", nullptr);
	juego.run();
	return 0;
}
