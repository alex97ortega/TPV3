#pragma once
class EstadoJuego
{
public:

	EstadoJuego()
	{
	}

	virtual ~EstadoJuego()
	{
	}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool onClick() = 0;
};

