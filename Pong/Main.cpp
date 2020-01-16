#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <Windows.h>

#define _WIN32_WINNT 0x0500

int main () {

#if NDEBUG
		HWND hWnd = GetConsoleWindow ();
	ShowWindow (hWnd, SW_HIDE);
#endif

	int windowWidth = 800;
	int windowHeight = 600;

	sf::RenderWindow window (sf::VideoMode (windowWidth, windowHeight), "Pong",sf::Style::Close);

	int score = 0;
	int lives = 3;

	Bat bat (windowWidth / 2, windowHeight - 20);
	Ball ball (windowWidth / 2, 1);

	sf::Text hud;
	sf::Font font;

	font.loadFromFile ("Chava.ttf");
	hud.setFont (font);
	hud.setCharacterSize (50);
	hud.setFillColor (sf::Color::Black);

	//Main Game Loop
	while (window.isOpen ()) {
		sf::Event event;

		//Handle Close event
		while (window.pollEvent (event)) {
			if (event.type == sf::Event::Closed) {
				window.close ();
			}
		}
		
		//Controlls
		if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left)) {
			bat.MoveLeft ();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bat.MoveRight ();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close ();
		}
		if (bat.getPosition ().left < 0){
			bat.ReboundToLeft ();
		}
		else if (bat.getPosition ().left  > windowWidth) {
			bat.ReboundToRight ();
		}

		//Handle Ball hitting the bottom
		if (ball.getPosition ().top > windowHeight) {
			ball.HitBottom ();
			lives--;

			if (lives < 1) {
				score = 0;
				lives = 3;
			}
		}

		//Handle Ball hitting the top
		if (ball.getPosition ().top < 0) {
			ball.ReboundBatOrTop ();
			score++;
		}

		//Handle Ball hitting sides
		if (ball.getPosition ().left < 0 || ball.getPosition ().left + 10 > windowWidth) {
			ball.ReboundSides ();
		}

		//Handle Ball hitting the Bat
		if (ball.getPosition ().intersects (bat.getPosition ())) {
			ball.ReboundBatOrTop();
		}

		//Update the Ball and Bat
		ball.Update ();
		bat.Update ();
		
#if _DEBUG
		std::cout << "Bat X: " << bat.getPosition ().left << std::endl;
#endif

		//Update the HUD
		std::stringstream ss;
		ss << "Score: " << score << "		Lives: " << lives;
		hud.setString (ss.str ());

		//Clear everything from the last frame
		window.clear (sf::Color (26, 128, 182, 255));

		//Draw Ball and Bat
		window.draw (bat.getShape ());
		window.draw (ball.getShape ());

		//Draw Score
		window.draw (hud);

		//Show everything
		window.display ();
	}

	return 0;
}