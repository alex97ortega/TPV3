#ifndef INPUTCOMPONENT_H_
#define INPUTCOMPONENT_H_

#include <SDL.h>
#include "GameObject.h"

class InputComponent {
public:
	InputComponent();
	virtual ~InputComponent();

	virtual void init(GameObject* o) = 0;
	virtual void handleInput(SDL_Event event, GameObject* o) = 0;
};

#endif /* INPUTCOMPONENT_H_ */
