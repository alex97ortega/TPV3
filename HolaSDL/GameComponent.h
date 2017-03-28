#ifndef GAMECOMPONENT_H_
#define GAMECOMPONENT_H_

#include "GameObject.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"

class GameComponent: public GameObject {
	InputComponent* inputComp_;
	PhysicsComponent* physicsComp_;
	RenderComponent* renderComp_;

public:
	GameComponent(SDLGame* game);
	virtual ~GameComponent();

	virtual void setInputComponent(InputComponent* inputComp);
	virtual void setPhysicsComponent(PhysicsComponent* physicsComp);
	virtual void setRenderComponent(RenderComponent* renderComp);

	// from GameObject
	virtual void update();
	virtual void handleInput(const SDL_Event& event);
	virtual void render();
};

#endif /* GAMECOMPONENT_H_ */
