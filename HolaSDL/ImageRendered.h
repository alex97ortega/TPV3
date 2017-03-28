#ifndef IMAGERENDERED_H_
#define IMAGERENDERED_H_

#include "RenderComponent.h"
#include "Texture.h"

class ImageRendered: public RenderComponent {
public:
	ImageRendered(Texture* texture);
	virtual ~ImageRendered();
	virtual void init(GameObject* o);
	virtual void render(GameObject* o);

private:
	Texture* texture_;
};

#endif /* IMAGERENDERED_H_ */
