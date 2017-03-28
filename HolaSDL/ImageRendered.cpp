#include "ImageRendered.h"

ImageRendered::ImageRendered(Texture* texture) : texture_(texture) {
}

ImageRendered::~ImageRendered() {
}

void ImageRendered::init(GameObject* o) {
}

void ImageRendered::render(GameObject* o) {
	if (texture_) {
		SDL_Rect dest { o->getPosition().getX(), o->getPosition().getY(),
				o->getWidth(), o->getHeight() };
		texture_->render(o->getGame()->getRenderer(), dest);
	}
}
