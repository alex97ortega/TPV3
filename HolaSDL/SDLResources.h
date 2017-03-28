/*
 * SDLResources.h
 *
 *  Created on: Mar 18, 2017
 *      Author: genaim
 */

#ifndef SDLRESOURCES_H_
#define SDLRESOURCES_H_

#include "Texture.h"
#include "Font.h"
#include "Music.h"
#include "SoundEffect.h"
#include <vector>

class SDLGame;
class SDLResources {
public:
	SDLResources(SDLGame* game);
	virtual ~SDLResources();

	void setTextures(std::vector<std::string> textures);
	void setFonts(std::vector<std::pair<std::string, int>> fonts);
	void setMusic(std::vector<std::string> music);
	void setSoundEffects(std::vector<std::string> soundEffects);

	Texture* getTexture(int i) const;
	Font* getFont(int i) const;
	Music* getMusic(int i) const;
	SoundEffect* getSoundEffect(int i) const;

private:
	void closeTextures();
	void closeFonts();
	void closeMusic();
	void closeSoundEffects();

	SDLGame* game_;

	int numOfTextures_;
	Texture** textures_;

	int numOfFonts_;
	Font** fonts_;

	int numOfMusic_;
	Music** music_;

	int numOfSoundEffects_;
	SoundEffect** soundEffects_;
};

#endif /* SDLRESOURCES_H_ */
