#include "Bat.h"

Bat::Bat (float startX, float startY) {
	position.x = startX;
	position.y = startY;

	batShape.setSize (sf::Vector2f (80, 5));
	batShape.setPosition (position);
}

sf::FloatRect Bat::getPosition () {
	return batShape.getGlobalBounds ();
}

sf::RectangleShape Bat::getShape () {
	return batShape;
}

void Bat::ReboundToRight () {
	position.x = 1;
}

void Bat::ReboundToLeft () {
	position.x = 800;
}

void Bat::MoveLeft () {
	position.x -= batSpeed;
}

void Bat::MoveRight () {
	position.x += batSpeed;
}

void Bat::Update () {
	batShape.setPosition (position);
}