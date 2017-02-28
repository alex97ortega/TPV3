#pragma once

#include "ObjetoPG.h"
class Vago :public ObjetoPG
{
public:
	Vago();
	~Vago();
	void draw(){ ; }
	bool onClick(){ return true; }
	void update(){ ; }
	void reiniciaPremio(){ ; }
};

