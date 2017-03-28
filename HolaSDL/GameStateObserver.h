#ifndef GAMEOBSERVER_H_
#define GAMEOBSERVER_H_

class GameStateObserver {
public:
	GameStateObserver();
	virtual ~GameStateObserver();

	virtual void onGameStart() = 0;
	virtual void onGameOver() = 0;
	virtual void onRoundStart() = 0;
	virtual void onRoundOver() = 0;
};

#endif /* GAMEOBSERVER_H_ */
