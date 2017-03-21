#pragma once

#include <string>
#include <stack>

class PBBVMprog 
{

public:

	enum INST {
		/*INCR_X, INCR_Y,*/ GET_DX, GET_DY, SET_DX, SET_DY, GET_CLICKS, DESACTIVATE,
		GET_POINTS, SET_POINTS, GAIN_POINTS, ADD, MUL, SUB, PUSH_N, GOTO_N, JMPZ_N, JMPGT_N};
	PBBVMprog(std::string file);
	~PBBVMprog();

	const char* getInstr() {
		return instr;
	}
	int getInstrucSize() { //tamaño de lista de inst
		return size;
	}

	

private:
	static void compile(std::string infile, std::string outfile);
	static const int MAX_SIZE = 100;
	char instr[MAX_SIZE];
	int size;
};

