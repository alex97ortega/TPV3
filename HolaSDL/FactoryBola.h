#pragma once
#include "FactoryBola.h"
#include "Factory.h"
#include "Globo.h"
#include "Mariposa.h"
#include "Premio.h"
#include "Vago.h"
#include "BouncingBall.h"

class FactoryBola :
	public Factory
{
public:
	FactoryBola(JuegoPG * juego);
	~FactoryBola();
};

