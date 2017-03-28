#include "GameComponent.h"

GameComponent::GameComponent(SDLGame* game) :
		GameObject(game), inputComp_(nullptr), physicsComp_(nullptr), renderComp_(
				nullptr) {
}

GameComponent::~GameComponent() {
}

void GameComponent::update() {
	if (physicsComp_) {
		physicsComp_->update(this);
	}
}

void GameComponent::handleInput(const SDL_Event& event) {
	if (inputComp_) {
		inputComp_->handleInput(event, this);
	}
}

void GameComponent::render() {
	if (renderComp_) {
		renderComp_->render(this);
	}
}

void GameComponent::setInputComponent(InputComponent* inputComp) {
	inputComp_ = inputComp;
	if (inputComp)
		inputComp->init(this);
}

void GameComponent::setPhysicsComponent(PhysicsComponent* physicsComp) {
	physicsComp_ = physicsComp;
	if (physicsComp)
		physicsComp->init(this);
}

void GameComponent::setRenderComponent(RenderComponent* renderComp) {
	renderComp_ = renderComp;
	if (renderComp)
		renderComp->init(this);
}
