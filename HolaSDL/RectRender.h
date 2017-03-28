#ifndef RECTRENDER_H_
#define RECTRENDER_H_

#include "RenderComponent.h"
#include <SDL.h>
#include "RenderComponent.h"

class RectRender : public RenderComponent {
	SDL_Color color_;
public:
	RectRender();
	RectRender(SDL_Color color);
	virtual ~RectRender();
	void init(GameObject *o);
	void render(GameObject *o);
};

#endif /* RECTRENDER_H_ */
