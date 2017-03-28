#include <string>
#include <cmath>
#include <random>

#include "GameManager.h"


GameManager::GameManager(SDLGame* game) :
		GameObject(game) {
	font_ = game_->getResources()->getFont(SDLGame::NESChimera16);
	SDL_Color color = { 255, 255, 255, 255 };
	startMsgTexture_.loadFromText(getGame()->getRenderer(),
			"Press Space to Start", *font_, color);
}

GameManager::~GameManager() {
}

void GameManager::update() {
}

void GameManager::handleInput(const SDL_Event& event) {
}

void GameManager::render() {

	// just an example, should be adjusted to the requirements!
	startMsgTexture_.render(getGame()->getRenderer(), (getGame()->getWindowWidth()-startMsgTexture_.getWidth())/ 2, getGame()->getWindowHeight()-40);
}

void GameManager::onCollision(GameObject* ball, GameObject* o) {
}

void GameManager::onBorderExit(GameObject* ball, BallObserver::EXIT_SIDE side) {
}

void GameManager::registerGameStateObserver(GameStateObserver* o) {
}
