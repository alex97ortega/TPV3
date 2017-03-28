#include "SDLResources.h"
#include "SDLGame.h"

SDLResources::SDLResources(SDLGame* game) :
		game_(game), numOfTextures_(0), textures_(nullptr), numOfFonts_(0), fonts_(
				nullptr), numOfMusic_(0), music_(nullptr), numOfSoundEffects_(
				0), soundEffects_(nullptr) {
}

void SDLResources::setTextures(std::vector<std::string> textures) {
	closeTextures();
	numOfTextures_ = textures.size();
	textures_ = new Texture*[numOfTextures_];
	for (int i = 0; i < numOfTextures_; i++) {
		textures_[i] = new Texture(game_->getRenderer(), textures[i]);
	}
}

void SDLResources::setFonts(std::vector<std::pair<std::string, int>> fonts) {
	closeFonts();
	numOfFonts_ = fonts.size();
	fonts_ = new Font*[numOfFonts_];
	for (int i = 0; i < numOfFonts_; i++) {
		fonts_[i] = new Font(fonts[i].first, fonts[i].second);
	}
}

void SDLResources::setMusic(std::vector<std::string> music) {
	closeMusic();
	numOfMusic_ = music.size();
	music_ = new Music*[numOfMusic_];
	for (int i = 0; i < numOfMusic_; i++) {
		music_[i] = new Music(music[i]);
	}
}

void SDLResources::setSoundEffects(std::vector<std::string> soundEffects) {
	closeSoundEffects();
	numOfSoundEffects_ = soundEffects.size();
	soundEffects_ = new SoundEffect*[numOfSoundEffects_];
	for (int i = 0; i < numOfSoundEffects_; i++) {
		soundEffects_[i] = new SoundEffect(soundEffects[i]);
	}
}

SDLResources::~SDLResources() {
	closeTextures();
	closeFonts();
	closeMusic();
	closeSoundEffects();
}

void SDLResources::closeTextures() {
	for (int i = 0; i < numOfTextures_; i++) {
		if (textures_[i] != nullptr) {
			delete textures_[i];
		}
	}
	delete[] textures_;
	numOfTextures_ = 0;

}

void SDLResources::closeFonts() {
	for (int i = 0; i < numOfFonts_; i++) {
		if (fonts_[i] != nullptr) {
			delete fonts_[i];
		}
	}
	delete[] fonts_;
	numOfFonts_ = 0;
}

void SDLResources::closeMusic() {
	for (int i = 0; i < numOfMusic_; i++) {
		if (music_[i] != nullptr) {
			delete music_[i];
		}
	}
	delete[] music_;
	numOfMusic_ = 0;
}

void SDLResources::closeSoundEffects() {
	for (int i = 0; i < numOfSoundEffects_; i++) {
		if (soundEffects_[i] != nullptr) {
			delete soundEffects_[i];
		}
	}
	delete[] soundEffects_;
	numOfSoundEffects_ = 0;
}

Texture* SDLResources::getTexture(int i) const {
	if (i < numOfTextures_)
		return textures_[i];
	else
		return nullptr;
}

Font* SDLResources::getFont(int i) const {
	if (i < numOfFonts_)
		return fonts_[i];
	else
		return nullptr;
}

Music* SDLResources::getMusic(int i) const {
	if (i < numOfMusic_)
		return music_[i];
	else
		return nullptr;
}

SoundEffect* SDLResources::getSoundEffect(int i) const {
	if (i < numOfSoundEffects_)
		return soundEffects_[i];
	else
		return nullptr;
}

