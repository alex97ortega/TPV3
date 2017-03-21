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
			pila.push(ball.getX()); 
			break;
		case PBBVMprog::GET_DY:
			pila.push(ball.getY());
			break;
		case PBBVMprog::SET_DX:
			ball.setX(pila.pop());
			break;
		case PBBVMprog::SET_DY:
			ball.setY(pila.pop);
			break;
		case PBBVMprog::GET_CLICKS:
			pila.push(ball.getClicks());
			break;
		case PBBVMprog::DESACTIVATE:
			ball.desactivate();
			break;
		case PBBVMprog::GET_POINTS:
			pila.push(ball.getPoints());
			break;
		case PBBVMprog::GAIN_POINTS:
			ball.gainPoints(p);
			break;
		case PBBVMprog::SET_POINTS:
			ball.setPoints(p);
			break;
		case PBBVMprog::ADD:
			pila.push(pila.pop() + pila.pop());
			break;
		case PBBVMprog::SUB:
			pila.push(pila.pop() - pila.pop());
			break;
		case PBBVMprog::MUL:
			pila.push(pila.pop() * pila.pop());
			break;
		case PBBVMprog::PUSH_N:
			pila.push(*((int*)(instr + pc + 1)));
			pc = pc + sizeof(int); // the for loop will add 
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