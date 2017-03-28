#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <iostream>

template<typename T>
class Vector2D {
	T x_;  // first coordinate
	T y_;  // second coordinate
public:
	Vector2D();
	Vector2D(const Vector2D<T> &v);
	Vector2D(T x, T y);
	virtual ~Vector2D();
	T getX() const;
	T getY() const;
	void setX(T x);
	void setY(T y);
	void set(const Vector2D<T> &v);
	void set(T x, T y);
	Vector2D<T> operator-(const Vector2D<T>& v) const {
		Vector2D<T> r;
		r.x_ = x_ - v.x_;
		r.y_ = y_ - v.y_;
		return r;
	}
	Vector2D<T> operator+(const Vector2D<T>& v) const {
		Vector2D<T> r;
		r.x_ = x_ + v.x_;
		r.y_ = y_ + v.y_;
		return r;
	}
	Vector2D<T> operator*(T d) const {
		Vector2D<T> r;
		r.x_ = x_ * d;
		r.y_ = y_ * d;
		return r;
	}

};


template<typename T>
inline Vector2D<T>::Vector2D() {
	x_ = T();
	y_ = T();
}

template<typename T>
inline Vector2D<T>::Vector2D(const Vector2D<T> &v) {
	x_ = v.x_;
	y_ = v.y_;
}

template<typename T>
inline Vector2D<T>::Vector2D(T x, T y) {
	this->x_ = x;
	this->y_ = y;
}

template<typename T>
inline Vector2D<T>::~Vector2D() {
}

template<typename T>
inline T Vector2D<T>::getX() const {
	return x_;
}

template<typename T>
inline T Vector2D<T>::getY() const {
	return y_;
}

template<typename T>
inline void Vector2D<T>::setX(T x) {
	this->x_ = x;
}

template<typename T>
inline void Vector2D<T>::setY(T y) {
	this->y_ = y;
}

template<typename T>
inline void Vector2D<T>::set(const Vector2D<T> &v) {
	x_ = v.x_;
	y_ = v.y_;
}

template<typename T>
inline void Vector2D<T>::set(T x, T y) {
	x_ = x;
	y_ = y;
}


#endif /* VECTOR2D_H_ */
