#include "SDLGame.h"
#include <time.h>


std::vector<std::string> SDLGame::imageFiles_ { "images/blank.png",
"images/tennis_ball.png", "images/keyboard.png", "images/mouse.png",
"images/ai.png" };


std::vector<std::pair<std::string, int>> SDLGame::fontFiles_ { {
		"fonts/ARIAL.ttf", 16 }, { "fonts/ARIAL.ttf", 24 }, {
			"fonts/NES-Chimera.ttf", 16 }, { "fonts/NES-Chimera.ttf", 24 }, {
				"fonts/Capture_it.ttf", 16 }, { "fonts/Capture_it.ttf", 24 } };

std::vector<std::string> SDLGame::musicFiles_ { "sound/beat.wav",
"sound/cheer.wav", "sound/boooo.wav" };

std::vector<std::string> SDLGame::soundEffectFiles_ { "sound/wall_hit.wav",
"sound/paddle_hit.wav" };

SDLGame::SDLGame(std::string windowTitle, int width, int height) :
		windowTitle_(windowTitle), width_(width), height_(height) {
	initSDL();
	initResources();
}

SDLGame::~SDLGame() {
	closeSDL();
}

void SDLGame::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	// SDL Fonts
	TTF_Init();

	// SDL Mixer (Music, Sound, etc)
	Mix_Init(
			MIX_INIT_FLAC | MIX_INIT_FLUIDSYNTH | MIX_INIT_MOD
					| MIX_INIT_MODPLUG | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// SDL Image
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

	// Create window .
	window_ = SDL_CreateWindow(windowTitle_.c_str(),
	SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN);

	// Create the renderer
	renderer_ = SDL_CreateRenderer(window_, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Clear screen (background color).
	SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);

	// initialize the seed of the random number generator;
	srand (time(NULL));

}

void SDLGame::closeSDL() {

	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;

	SDL_DestroyWindow(window_);
	window_ = nullptr;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();

	SDL_Quit();
}

void SDLGame::initResources() {
	resources_ = new SDLResources(this);
	resources_->setTextures(imageFiles_);
	resources_->setFonts(fontFiles_);
	resources_->setMusic(musicFiles_);
	resources_->setSoundEffects(soundEffectFiles_);
}

void SDLGame::closeResources() {
	delete resources_;
}

SDL_Window* SDLGame::getWindow() const {
	return window_;
}

SDL_Renderer* SDLGame::getRenderer() const {
	return renderer_;
}

const SDLResources* SDLGame::getResources() const {
	return resources_;
}

int SDLGame::getWindowWidth() const {
	return width_;
}

int SDLGame::getWindowHeight() const {
	return height_;
}

