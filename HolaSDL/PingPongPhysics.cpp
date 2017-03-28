#include <cmath>
#include <random>
#include "PingPongPhysics.h"

PingPongPhysics::PingPongPhysics(GameObject* left_paddle,
		GameObject* right_paddle) :
		left_paddle_(left_paddle), right_paddle_(right_paddle), hits_(
				0), speed_(0) {
}

PingPongPhysics::~PingPongPhysics() {
}

void PingPongPhysics::init(GameObject* o) {
}

void PingPongPhysics::update(GameObject* o) {
}


void PingPongPhysics::resgisterBallObserver(BallObserver* o) {
}


void PingPongPhysics::onGameStart() {
}

void PingPongPhysics::onGameOver() {
}

void PingPongPhysics::onRoundStart() {
}

void PingPongPhysics::onRoundOver() {
}

