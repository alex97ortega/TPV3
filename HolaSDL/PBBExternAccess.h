#pragma once
class PBBExternAccess
{
public:

	PBBExternAccess(){}
	virtual ~PBBExternAccess(){}


	virtual void incrX() = 0;
	virtual void incrY() = 0;
	virtual void onClick() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual void setX(int) = 0;
	virtual void setY(int) = 0;

	int alto, ancho, pimgx, pimgy;
};

