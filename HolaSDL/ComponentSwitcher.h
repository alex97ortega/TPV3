#ifndef COMPONENTSWITCHER_H_
#define COMPONENTSWITCHER_H_

#include <SDL.h>
#include <vector>

#include "GameObject.h"
#include "GameComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"

class ComponentSwitcher: public GameObject {
public:

	ComponentSwitcher(SDLGame* game, GameComponent* actor, SDL_Keycode ctrlKey);
	virtual ~ComponentSwitcher();

	virtual void switchToNext();
	virtual void setMode(int i);
	virtual void addMode(InputComponent* inputComp,
			PhysicsComponent* physicsComp, RenderComponent* renderComp,
			RenderComponent* modeRendered);

	// from GameObject
	virtual void update();
	virtual void handleInput(const SDL_Event& event);
	virtual void render();

private:
	GameComponent* actor_;
	SDL_Keycode ctrlKey_;

};

#endif /* COMPONENTSWITCHER_H_ */
