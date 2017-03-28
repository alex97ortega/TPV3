#ifndef STOPONBORDERSPHYSICS_H_
#define STOPONBORDERSPHYSICS_H_

#include "PhysicsComponent.h"

class StopOnBordersPhysics: public PhysicsComponent {
public:
	StopOnBordersPhysics(bool left, bool right, bool top, bool bottom);
	virtual ~StopOnBordersPhysics();
	virtual void init(GameObject* o);
	virtual void update(GameObject* o);
private:
	bool left_;
	bool right_;
	bool top_;
	bool bottom_;
};

#endif /* STOPONBORDERSPHYSICS_H_ */
