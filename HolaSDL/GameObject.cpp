#include "GameObject.h"

GameObject::GameObject(SDLGame* game) :
		game_(game), active_(true), moving_(true), width_(), height_(), pos_(), dir_() {
}

GameObject::GameObject(SDLGame* game, int width, int height, Vector2D<int> pos,
		Vector2D<int> dir) :
		game_(game), active_(true), moving_(true), width_(width), height_(
				height), pos_(pos), dir_(dir) {
}

GameObject::~GameObject() {
}

SDLGame* GameObject::getGame() const {
	return game_;
}

bool GameObject::isActive() const {
	return active_;
}

void GameObject::setActive(bool active) {
	active_ = active;
}

bool GameObject::toggleActive() {
	return moving_ = !moving_;
}

bool GameObject::isMoving() const {
	return moving_;
}

void GameObject::setMoving(bool moving) {
	moving_ = moving;
}

bool GameObject::toggleMoving() {
	return moving_ = !moving_;
}

int GameObject::getHeight() const {
	return height_;
}

int GameObject::getWidth() const {
	return width_;
}

void GameObject::setWidth(int width) {
	width_ = width;
}

void GameObject::setHeight(int height) {
	height_ = height;
}

const Vector2D<int>& GameObject::getPosition() const {
	return pos_;
}

void GameObject::setPosition(const Vector2D<int>& pos) {
	pos_.set(pos);
}

void GameObject::setPositionX(int x) {
	pos_.setX(x);
}

void GameObject::setPositionY(int y) {
	pos_.setY(y);
}

void GameObject::setPosition(int x, int y) {
	pos_.setX(x);
	pos_.setY(y);
}

const Vector2D<int>& GameObject::getDirection() const {
	return dir_;
}

void GameObject::setDirection(const Vector2D<int>& dir) {
	dir_.set(dir);
}

void GameObject::setDirectionX(int x) {
	dir_.setX(x);
}

void GameObject::setDirectionY(int y) {
	dir_.setY(y);
}

void GameObject::setDirection(int x, int y) {
	dir_.set(x, y);
}
