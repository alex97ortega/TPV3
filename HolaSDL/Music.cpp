#include "Music.h"

Music::Music() :
		music_(nullptr) {
}

Music::Music(std::string fileName) :
		music_(nullptr) {
	load(fileName);
}

Music::~Music() {
}

bool Music::load(std::string fileName) {
	close();
	music_ = Mix_LoadMUS(fileName.c_str());
	return music_ != nullptr;
}

void Music::play(int repetitions) {
	Mix_PlayMusic(music_, repetitions);
}

void Music::pause() {
	Mix_PauseMusic();
}

void Music::close() {
	if (music_ != nullptr) {
		Mix_FreeMusic(music_);
		music_ = nullptr;
	}
}
