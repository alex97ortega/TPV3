#ifndef SIMPLEMOVEPHYSICS_H_
#define SIMPLEMOVEPHYSICS_H_

#include "PhysicsComponent.h"

class SimpleMovePhysics: public PhysicsComponent {
public:
	SimpleMovePhysics();
	virtual ~SimpleMovePhysics();
	void init(GameObject *o);
	void update(GameObject *o);
};

#endif /* SIMPLEMOVEPHYSICS_H_ */
