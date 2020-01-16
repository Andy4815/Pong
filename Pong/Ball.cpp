#include "Ball.h"

Ball::Ball (float startX, float startY) {
	position.x = startX;
	position.y = startY;

	ballshape.setSize (sf::Vector2f (10, 10));
	ballshape.setPosition (position);
}

sf::FloatRect Ball::getPosition () {
	return ballshape.getGlobalBounds ();
}

sf::RectangleShape Ball::getShape () {
	return ballshape;
}

float Ball::getXVelocity () {
	return xVelocity;
}

void Ball::ReboundSides () {
	xVelocity = -xVelocity;
}

void Ball::ReboundBatOrTop () {
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

void Ball::HitBottom () {
	position.y = 1;
	position.x = 500;
}

void Ball::Update () {
	position.y += yVelocity;
	position.x += xVelocity;

	ballshape.setPosition (position);
}