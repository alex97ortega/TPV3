#include "RectRender.h"
#include "SDLGame.h"

RectRender::RectRender() :
		color_( { 255, 255, 255, 255 }) {
}

RectRender::RectRender(SDL_Color color) :
		color_(color) {
}

RectRender::~RectRender() {
}

void RectRender::init(GameObject* o) {
}

void RectRender::render(GameObject* o) {

	const Vector2D<int> &pos = o->getPosition();
	SDLGame* game = o->getGame();
	SDL_Renderer* renderer = game->getRenderer();

	SDL_Rect rect =
			{ pos.getX(), pos.getY(), o->getWidth(), o->getHeight() };

	SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);

	SDL_RenderFillRect(renderer, &rect);
}
