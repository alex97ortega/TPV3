#ifndef BALLOBSERVER_H_
#define BALLOBSERVER_H_

#include "GameObject.h"

class BallObserver {
public:
	enum EXIT_SIDE {
		LEFT, RIGHT, TOP, BOT
	};

	BallObserver();
	virtual ~BallObserver();

	virtual void onCollision(GameObject* ball, GameObject* o) = 0;
	virtual void onBorderExit(GameObject* ball, BallObserver::EXIT_SIDE) = 0;
};

#endif /* BALLOBSERVER_H_ */
