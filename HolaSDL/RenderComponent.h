#ifndef RENDERCOMPONENT_H_
#define RENDERCOMPONENT_H_

#include "GameObject.h"

class RenderComponent {
public:
	RenderComponent();
	virtual ~RenderComponent();
	virtual void init(GameObject* o) = 0;
	virtual void render(GameObject* o) = 0;
};

#endif /* RENDERCOMPONENT_H_ */
