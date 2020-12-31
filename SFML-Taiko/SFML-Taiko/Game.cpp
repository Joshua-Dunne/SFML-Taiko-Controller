#include "Game.h"

Game::Game() :	m_window(sf::VideoMode(800u, 600u), "Taiko DEMO")
{
	m_window.setFramerateLimit(60u);
}

Game::~Game()
{
	// unused
}

/// <summary>
/// Run the main Game loop
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	while (m_window.isOpen())
	{
		processInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();
	}
}

void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time& dt)
{
	// update game objects
}

void Game::render()
{
	m_window.clear(sf::Color::Black);

	// draw game objects

	m_window.display();
}
