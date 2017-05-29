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
	int addr[MAX_SIZE];
	bool pending[MAX_SIZE];

	std::string keyword;
	int  pc = 0;
	int bytecodeNum = -1;


	while (!in.eof()) {
		in >> keyword;
		if (in.good()) {
			bytecodeNum++;
			addr[bytecodeNum] = pc;
			pending[bytecodeNum] = false;
			std::cout << "Compiling: " << keyword << std::endl;

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
				int n;
				in >> n;
				bytecode[pc++] = GOTO_N;
				if (n < bytecodeNum){
					(*((int*)(bytecode + pc + 1))) = addr[n];
				}
				else {
					pending[pc] = true;
					(*((int*)(bytecode + pc + 1))) = n;
				}
				pc = pc + sizeof(int);
			}


			else if (keyword == "JMPZ_N") {
				int n;
				in >> n;
				bytecode[pc++] = JMPZ_N;
				if (n < bytecodeNum){
					(*((int*)(bytecode + pc + 1))) = addr[n];
				}
				else {
					pending[pc] = true;
					(*((int*)(bytecode + pc + 1))) = n;
				}
				pc = pc + sizeof(int);
			}
		}
		else if (keyword == "JMPGT_N") {
			int n;
			in >> n;
			bytecode[pc++] = JMPGT_N;
			if (n < bytecodeNum){
				(*((int*)(bytecode + pc + 1))) = addr[n];
			}
			else {
				pending[pc] = true;
				(*((int*)(bytecode + pc + 1))) = n;
			}
			pc = pc + sizeof(int);
		}

		else {
			throw "Error!";
		}
	}


	for (int i = 0; i < bytecodeNum; i++) {
		if (pending[i]) {
			int n = (*(int*)(bytecode + addr[i] + 1));
			if (n >= bytecodeNum)
				(*(int*)(bytecode + addr[i] + 1)) = pc;
			else{
				(*(int*)(bytecode + addr[i] + 1)) = addr[n];
			}
		}
	}


	out.write(bytecode, pc);
	in.close();
	out.close();

}

