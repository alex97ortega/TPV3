#ifndef BOUNCEONBORDERS_H_
#define BOUNCEONBORDERS_H_

#include "PhysicsComponent.h"
#include "SoundEffect.h"

/*
 *
 */
class BounceOnBorders: public PhysicsComponent {
public:
	BounceOnBorders(bool left, bool right, bool top, bool bottom);
	virtual ~BounceOnBorders();
	virtual void init(GameObject* o);
	virtual void update(GameObject* o);
private:
	bool left_;
	bool right_;
	bool top_;
	bool bottom_;

	SoundEffect* wallHitSound_;
};

#endif /* BOUNCEONBORDERS_H_ */
