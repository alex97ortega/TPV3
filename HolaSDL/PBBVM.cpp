#include "PBBVM.h"



PBBVM::PBBVM()
{
}


PBBVM::~PBBVM()
{
}
void PBBVM::run(PBBVMprog& prog, PBBExternAccess& ball) {
	const char* instr = prog.getInstr();
	int size = prog.getInstrucSize();
	for (int pc = 0; pc < size; pc++) {
		switch (instr[pc]) {
		case PBBVMprog::INCR_X:
			ball.incrX();
			break;
		case PBBVMprog::INCR_Y:
			ball.incrY();
			break; // meter más instrucciones		
		}
	}
}