#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "SDLGame.h"
#include "Vector2D.h"

class GameObject {
protected:
	SDLGame* game_; // pointer to the game

	bool active_;   // indicates if the object is active
	bool moving_;   // indicates if the object is in standby (active but not moving)

	int width_;  // width
	int height_; // height

	Vector2D<int> pos_; // position
	Vector2D<int> dir_; // direction

public:
	GameObject(SDLGame* game);
	GameObject(SDLGame* game, int width, int height, Vector2D<int> pos, Vector2D<int> dir);
	virtual ~GameObject();

	SDLGame* getGame() const;

	bool isActive() const;
	void setActive(bool active);
	bool toggleActive();

	bool isMoving() const;
	void setMoving(bool moving);
	bool toggleMoving();

	int getWidth() const;
	void setWidth(int width);

	const Vector2D<int>& getPosition() const;
	void setPosition(const Vector2D<int> &pos);
	void setPositionX(int x);
	void setPositionY(int y);
	void setPosition(int x, int y);

	int getHeight() const;
	void setHeight(int height);

    const Vector2D<int>& getDirection() const;
	void setDirection(const Vector2D<int> &dir);
	void setDirectionX(int x);
	void setDirectionY(int y);
	void setDirection(int x, int y);

	// abstract methods to be implemented in sub-classes
	virtual void handleInput(const SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif /* GAMEOBJECT_H_ */
