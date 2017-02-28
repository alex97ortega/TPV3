#pragma once

#include "ObjetoPG.h"
class Vago :public ObjetoPG
{
public:
	Vago();
	~Vago();
	void draw();
	bool onClick();
	void update();
	void reiniciaPremio();
};

