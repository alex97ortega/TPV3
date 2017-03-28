#include "PaddleKeyboardInputComp.h"

PaddleKeyboardInputComp::PaddleKeyboardInputComp(SDL_Keycode up_key,
		SDL_Keycode down_key, SDL_Keycode stop_key, unsigned int velocity) :
		InputComponent() {
	up_key_ = up_key;
	down_key_ = down_key;
	stop_key_ = stop_key;
	velocity_ = velocity;
}

void PaddleKeyboardInputComp::init(GameObject* paddle) {
}

void PaddleKeyboardInputComp::handleInput(SDL_Event event, GameObject* paddle) {
}

PaddleKeyboardInputComp::~PaddleKeyboardInputComp() {
}
