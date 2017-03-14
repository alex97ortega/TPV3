#include "PBBVM.h"



PBBVM::PBBVM()
{
	p = 100;
}


PBBVM::~PBBVM()
{
}
void PBBVM::run(PBBVMprog& prog, PBBExternAccess& ball) {
	const char* instr = prog.getInstr();
	int size = prog.getInstrucSize();
	for (int pc = 0; pc < size; pc++) {
		switch (instr[pc]) {
		/*case PBBVMprog::INCR_X:
			ball.incrX();
			break;
		case PBBVMprog::INCR_Y:
			ball.incrY();
			break; // meter más instrucciones	*/
		case PBBVMprog::GET_DX:
			ball.getX();
			break;
		case PBBVMprog::GET_DY:
			ball.getY();
			break;
		case PBBVMprog::SET_DX:
			ball.setX(1);
			break;
		case PBBVMprog::SET_DY:
			ball.setY(1);
			break;
		case PBBVMprog::DESACTIVATE:
			ball.desactivate();
			break;
		case PBBVMprog::GET_POINTS:
			ball.getPoints();
			break;
		case PBBVMprog::GAIN_POINTS:
			ball.gainPoints(p);
			break;
		case PBBVMprog::SET_POINTS:
			ball.setPoints(p);
			break;
		case PBBVMprog::ADD:
			ball.add();
			break;
		case PBBVMprog::SUB:
			ball.sub();
			break;
		case PBBVMprog::MUL:
			ball.mul();
			break;
		case PBBVMprog::PUSH_N:
			ball.push_n(1);
			break;
		case PBBVMprog::GOTO_N:
			ball.goto_n(1);
			break;
		case PBBVMprog::JMPZ_N:
			ball.jmpz_n();
			break;
		case PBBVMprog::JMPGT_N:
			ball.jmpgt_n();
			break;
		}
	}
}