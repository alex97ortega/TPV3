#include "PBBVMprog.h"
#include <ostream>
#include <fstream>
#include <iostream>


PBBVMprog::PBBVMprog(std::string file)
{
}


PBBVMprog::~PBBVMprog()
{
}


void PBBVMprog::compile(std::string infile, std::string outfile) {
	std::ifstream in;
	std::ofstream out;

	in.open(infile);
	out.open(outfile, std::ios::binary);

	char bytecode[MAX_SIZE];

	std::string keyword;
	int  pc = 0;

	while (!in.eof()) {
		in >> keyword;
		if (in.good()) {
			std::cout << "Compiling: " << keyword << std::endl;
			/*if (keyword == "increment_x") {
				bytecode[pc++] = INCR_X;
			}
			else if (keyword == "increment_y") {
				bytecode[pc++] = INCR_Y;
			}*/
			/*else */
			if (keyword == "GET_DX") {
				bytecode[pc++] = GET_DX;
			}
			else if (keyword == "GET_DY") {
				bytecode[pc++] = GET_DY;
			}
			else if (keyword == "SET_DX") {
				bytecode[pc++] = SET_DX;
			}
			else if (keyword == "SET_DY") {
				bytecode[pc++] = SET_DY;
			}
			else if (keyword == "DESACTIVATE") {
				bytecode[pc++] = DESACTIVATE;
			}
			else if (keyword == "GET_CLICKS") {
				bytecode[pc++] = GET_CLICKS;
			}
			else if (keyword == "GET_POINTS") {
				bytecode[pc++] = GET_POINTS;
			}
			else if (keyword == "SET_POINTS") {
				bytecode[pc++] = SET_POINTS;
			}
			else if (keyword == "GAIN_POINTS") {
				bytecode[pc++] = GAIN_POINTS;
			}
			else if (keyword == "ADD") {
				bytecode[pc++] = ADD;
			}
			else if (keyword == "SUB") {
				bytecode[pc++] = SUB;
			}
			else if (keyword == "MUL") {
				bytecode[pc++] = MUL;
			}
			else if (keyword == "PUSH_N") {
				bytecode[pc++] = PUSH_N;
			}
			else if (keyword == "GOTO_N") {
				bytecode[pc++] = GOTO_N;
			}
			else if (keyword == "JMPZ_N") {
				bytecode[pc++] = JMPZ_N;
			}
			else if (keyword == "JMPGT_N") {
				bytecode[pc++] = JMPGT_N;
			}
			else {
				throw "Error!";
			} 
		}
	}
	out.write(bytecode, pc);

	in.close();
	out.close();
}

