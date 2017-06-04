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

		case PBBVMprog::GET_DX:
			pila.push(ball.getX()); 
			break;
		case PBBVMprog::GET_DY:
			pila.push(ball.getY());
			break;
		case PBBVMprog::SET_DX:
			ball.setX(pila.top());
			pila.pop();
			break;
		case PBBVMprog::SET_DY:
			ball.setY(pila.top());
			pila.pop();
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
			ball.gainPoints(pila.top());
			pila.pop();
			break;
		case PBBVMprog::SET_POINTS:
			ball.setPoints(pila.top());
			pila.pop();
			break;
		case PBBVMprog::ADD:
			a = pila.top();
			pila.pop();
			b = pila.top();
			pila.pop();
			pila.push(a + b);
			break;
		case PBBVMprog::SUB:
			a = pila.top();
			pila.pop();
			b = pila.top();
			pila.pop();
			pila.push(a - b);
			break;
		case PBBVMprog::MUL:
			a = pila.top();
			pila.pop();
			b = pila.top();
			pila.pop();
			pila.push(a * b);
			break;
		case PBBVMprog::PUSH_N:
			pila.push(*((int*)(instr + pc + 1)));
			pc = pc + sizeof(int);
			break;
		case PBBVMprog::GOTO_N:
			pc = (*((int*)(instr + pc + 1)) - 1);
			break;
		case PBBVMprog::JMPZ_N:
			if (pila.top() == 0)
				pc = (*((int*)(instr + pc + 1)));
			pila.pop();
			break;
		case PBBVMprog::JMPGT_N:
			a = pila.top();
			pila.pop();
			b = pila.top();
			pila.pop();
			if (a > b)
				pc = (*((int*)(instr + pc + 1)));
			break;
		}
	}
}