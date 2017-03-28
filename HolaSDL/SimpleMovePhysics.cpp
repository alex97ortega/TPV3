#include "SimpleMovePhysics.h"

SimpleMovePhysics::SimpleMovePhysics() {
}

SimpleMovePhysics::~SimpleMovePhysics() {
}

void SimpleMovePhysics::init(GameObject* o) {
}

void SimpleMovePhysics::update(GameObject* o) {
	if (o->isActive() && o->isMoving()) {
		o->setPosition(o->getPosition() + o->getDirection());
	}
}

