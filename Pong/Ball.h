#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
	sf::Vector2f position;
	sf::RectangleShape ballshape;

public:
	Ball (float startX, float startY);

	float xVelocity = .3f;
	float yVelocity = .3f;
	
	sf::FloatRect getPosition ();
	sf::RectangleShape getShape ();

	float getXVelocity ();
	
	void ReboundSides ();
	void ReboundBatOrTop ();
	void HitBottom ();
	void Update ();
};