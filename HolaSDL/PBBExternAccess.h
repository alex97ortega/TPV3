#pragma once
class PBBExternAccess
{
public:

	PBBExternAccess(){}
	virtual ~PBBExternAccess(){}



	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual void setX(int) = 0;
	virtual void setY(int) = 0;
	virtual int getClicks() = 0;
	virtual void desactivate() = 0;
	virtual int getPoints() = 0;
	virtual void setPoints(int) = 0;
	virtual void gainPoints(int) = 0;
	/*virtual void add() = 0;
	virtual void sub() = 0;
	virtual void mul() = 0;
	virtual void push_n(int i) = 0;
	virtual void goto_n(int i) = 0;
	virtual void jmpz_n() = 0;
	virtual void jmpgt_n() = 0;*/

};

