#ifndef PHYSICSCOMPONENT_H_
#define PHYSICSCOMPONENT_H_

#include "GameObject.h"

class PhysicsComponent {
public:
	PhysicsComponent();
	virtual ~PhysicsComponent();

	virtual void init(GameObject* o) = 0;
	virtual void update(GameObject* o) = 0;
};

#endif /* PHYSICSCOMPONENT_H_ */
