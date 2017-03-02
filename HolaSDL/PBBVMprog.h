#pragma once

#include <string>
class PBBVMprog 
{

public:

	enum INST { INCR_X, INCR_Y}; // hay que añadir más instr
	PBBVMprog(std::string file);
	~PBBVMprog();

	const char* getInstr() {
		return instr;
	}
	int getInstrucSize() { //tamaño de lista de inst
		return size;
	}
private:

	static const int MAX_SIZE = 100;
	char instr[MAX_SIZE];
	int size;
};

