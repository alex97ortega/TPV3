#ifndef PADDLEKEYBOARDINPUTCOMP_H_
#define PADDLEKEYBOARDINPUTCOMP_H_

#include <SDL.h>
#include "InputComponent.h"


class PaddleKeyboardInputComp: public InputComponent {
public:
	PaddleKeyboardInputComp(SDL_Keycode up_key, SDL_Keycode down_key,
			SDL_Keycode stop_key, unsigned int velocity);
	virtual ~PaddleKeyboardInputComp();

	// from InputComponent
	virtual void init(GameObject* paddle);
	virtual void handleInput(SDL_Event e, GameObject* o);

private:
	SDL_Keycode up_key_;
	SDL_Keycode down_key_;
	SDL_Keycode stop_key_;
	unsigned int velocity_;


};

#endif /* PADDLEKEYBOARDINPUTCOMP_H_ */
