#ifndef SDLGAME_H_
#define SDLGAME_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "SDLResources.h"

class SDLGame {
public:
	// in this part we define the enums for the resources, and the
	// corresponding data to be used to create them. The enums are simple
	// used to make access readable ...

	// Images -- each image file is loaded as an instance of Texture
	//
	enum ImageId {
		Blank, TennisBall, KeyBoardIcon, MouseIcon, AIIcon
	};

	static std::vector<std::string> imageFiles_;

	// Fonts -- they are pair of filename and size, each is loaded as
	// an instance of Font
	//
	enum FontId {
		ARIAL16, ARIAL24, NESChimera16, NESChimera24, CaptureIt16, CaptureIt24
	};

	static std::vector<std::pair<std::string, int>> fontFiles_;

	// Music -- each file is loaded as an instance of Music
	//
	enum MusicIds {
		Beat, Cheer, Boooo
	};

	static std::vector<std::string> musicFiles_;

	// Sound Effects -- each file is loaded as an instance of SoundEffect
	//
	enum SoundEffectId {
		Wall_Hit, Paddle_Hit
	};

	static std::vector<std::string> soundEffectFiles_;

public:
	SDLGame(std::string windowTitle_, int width, int height);
	virtual ~SDLGame();

	SDL_Window* getWindow() const; // returns a pointer to the SDL window
	SDL_Renderer* getRenderer() const; // returns a pointer to the SDL renderer
	int getWindowWidth() const; // returns the window width
	int getWindowHeight() const; // returns the window height
	const SDLResources* getResources() const; // returns a pointer to the resources

	// abstract methods to be implemented by subclasses
	virtual void start() = 0; // start the game
	virtual void stop() = 0;  // stop the game

private:
	void initSDL(); // initialize SDL (ttf, mixer, image, create window and renderer, etc)
	void closeSDL(); // close all SDL resources
	void initResources(); // initialize the SDLResources object with the data at the top of this file
	void closeResources(); // close the  SDLResources object (frees all memory)

protected:
	SDL_Window* window_; // the window
	SDL_Renderer* renderer_;  // the renderer
	SDLResources* resources_; // resource (textures, font, music, etc)

	std::string windowTitle_; // window title
	int width_; // window width
	int height_; // window height

};

#endif /* SDLGAME_H_ */
