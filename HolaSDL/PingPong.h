#ifndef PINGPONG_H_
#define PINGPONG_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

#include "SDLGame.h"
#include "GameObject.h"
#include "GameComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "GameManager.h"

class PingPong: public SDLGame {

public:
	PingPong();
	virtual ~PingPong();

	// from SDLGame
	void start();
	void stop();

private:
	void initGame();
	void closeGame();
	void handleInput();
	void update();
	void render();

	const static int _WINDOW_WIDTH_ = 640;
	const static int _WINDOW_HEIGHT_ = 480;

	GameComponent* ball_;
	GameComponent* left_paddle_;
	GameComponent* right_paddle_;
	GameManager* gameManager_;

	PhysicsComponent* bounceOnBorderPhysics_;
	RenderComponent* rectangleRenderer_;
	RenderComponent* imageRenderer_;

	std::vector<GameObject*> actors_;

	bool exit_;

};

#endif /* PINGPONG_H_ */
