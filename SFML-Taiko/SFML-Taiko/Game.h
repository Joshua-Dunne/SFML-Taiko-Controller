#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Taiko.h"
#include "BoxVisual.h"

class Game
{
public:
	Game();
	~Game();
private:
	sf::RenderWindow m_window;
	sf::Clock m_updateClock;

	Taiko m_drum;

	static const int m_numOfVisuals = 4; // we only need 4 visuals (2 edge, 2 mid) but this looks cleaner
	BoxVisual* m_visuals[m_numOfVisuals];

public:
	void run();
	void processInput();
	void update(sf::Time& dt);
	void render();
};

#endif