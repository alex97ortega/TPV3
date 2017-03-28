#include "BounceOnBorders.h"


BounceOnBorders::BounceOnBorders(bool left, bool right, bool top, bool bottom) :
		left_(left), right_(right), top_(top), bottom_(bottom) {
	wallHitSound_ = nullptr;
}

BounceOnBorders::~BounceOnBorders() {
}

void BounceOnBorders::init(GameObject* o) {
	wallHitSound_ = o->getGame()->getResources()->getSoundEffect(SDLGame::Wall_Hit);
}

void BounceOnBorders::update(GameObject* o) {
	Vector2D<int> nextPos = o->getPosition() + o->getDirection();

// check if we exit from top/bottpm
	if (top_ && nextPos.getY() <= 0) {
		nextPos.setY(0);
		o->setPosition(nextPos);
		o->setDirectionY( -1*o->getDirection().getY() );
		wallHitSound_->play();
	}

	if (bottom_
			&& nextPos.getY()
					>= o->getGame()->getWindowHeight() - o->getHeight()) {
		nextPos.setY(o->getGame()->getWindowHeight() - o->getHeight());
		o->setDirectionY( -1*o->getDirection().getY() );
		wallHitSound_->play();
	}

    // check if we exit from left/right
	if (left_ && nextPos.getX() <= 0) {
		nextPos.setX(0);
		o->setPosition(nextPos);
		o->setDirectionX( -1*o->getDirection().getX() );
		wallHitSound_->play();
	}

	if (right_
			&& nextPos.getX()
					>= o->getGame()->getWindowWidth() - o->getWidth()) {
		nextPos.setX(o->getGame()->getWindowWidth() - o->getWidth());
		o->setDirectionX( -1*o->getDirection().getX() );
		wallHitSound_->play();
	}

	o->setPosition(nextPos);

}
