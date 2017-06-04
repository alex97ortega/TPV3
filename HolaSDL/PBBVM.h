#pragma once
#include "PBBVMprog.h"
#include "PBBExternAccess.h"
class PBBVM // representa la m�quina virtual
{
public:
	PBBVM();
	~PBBVM();

	void run(PBBVMprog& prog, PBBExternAccess& ball);
	int p;
	std::stack<int> pila;
	int a;
	int b;
};

