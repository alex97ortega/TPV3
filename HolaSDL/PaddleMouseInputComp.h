#ifndef PADDLEMOUSEINPUTCOMP_H_
#define PADDLEMOUSEINPUTCOMP_H_

#include "InputComponent.h"

class PaddleMouseInputComp: public InputComponent {
public:
	PaddleMouseInputComp();
	virtual ~PaddleMouseInputComp();

	// from InputComponent
	void init(GameObject* paddle);
	void handleInput(SDL_Event e, GameObject* paddle);
};

#endif /* PADDLEMOUSEINPUTCOMP_H_ */
