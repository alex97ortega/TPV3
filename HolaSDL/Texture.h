#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL.h>
#include <SDL_image.h>
#include "Font.h"

class Texture {
public:
	Texture();
	Texture(SDL_Renderer* renderer, std::string fileName);
	Texture(SDL_Renderer* renderer, std::string text, const Font& font,
			const SDL_Color color);
	virtual ~Texture();

	int getWidth();
	int getHight();
	bool loadFromImg(SDL_Renderer* renderer, std::string fileName);
	bool loadFromText(SDL_Renderer * pRender, std::string texto,
			Font const& font, SDL_Color color = { 0, 0, 0, 255 });
	void render(SDL_Renderer* renderer, int x, int y) const;
	void render(SDL_Renderer* renderer, SDL_Rect const& dest, SDL_Rect* clip =
			nullptr) const;
	void close();

private:

	SDL_Texture *texture_;
	int width_;
	int height_;
};

#endif /* TEXTURE_H_ */
