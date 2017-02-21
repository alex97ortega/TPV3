#include "FactoryPG.h"
#include "Factory.h"
#include "Globo.h"



FactoryPG::FactoryPG()
{
	
}


FactoryPG::~FactoryPG()
{
}

ObjetoJuego*Factory::createNormalElement(char tipo)
{
	if (tipo == 'G'){
		//return new Globo(ptsjuego, JuegoPG::TGlobo, rand() % 700, rand() % 700);
	}
	else if (tipo == 'B'){

	}
}

ObjetoJuego*Factory::createSpecialElement(char tipo)
{
	if (tipo == 'M'){

	}
}

ObjetoJuego*Factory::createPrizeElement(char tipo)
{
	if (tipo == 'P'){}
}