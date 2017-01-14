#pragma once
#include "ObjetoPG.h"

class Boton : public ObjetoPG
{
public:
	typedef void CallBack_t(JuegoPG* jg);

protected:
	CallBack_t * cb;

public:
	Boton(CallBack_t * cbCons);
	~Boton();
};

