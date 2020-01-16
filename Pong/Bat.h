#pragma once
#include <SFML/Graphics.hpp>

class Bat {
private:
	sf::Vector2f position;
	sf::RectangleShape batShape;
	
	float batSpeed = 0.5f;

public:
	Bat (float startX, float startY);
	sf::FloatRect getPosition ();
	sf::RectangleShape getShape ();

	void ReboundToLeft ();
	void ReboundToRight ();
	void MoveLeft ();
	void MoveRight ();
	void Update ();
};
