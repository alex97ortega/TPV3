#ifndef PADDLEAIPHYSICS_H_
#define PADDLEAIPHYSICS_H_

#include "PhysicsComponent.h"

class PaddleAIPhysics : public PhysicsComponent {
public:
	PaddleAIPhysics();
	PaddleAIPhysics(GameObject* ball);
	virtual ~PaddleAIPhysics();

	// from PhysicsComponent
	virtual void init(GameObject* paddle);
	virtual void update(GameObject* paddle);

private:
	GameObject* ball_;
};

#endif /* PADDLEAIPHYSICS_H_ */
