#include "Game.h"

Game::Game() : m_window(sf::VideoMode(800u, 600u), "Taiko DEMO"), m_drum{ 0u }
{
	m_window.setFramerateLimit(60u);

	m_visuals[0] = new BoxVisual(0, 200.0f, sf::Color::Blue);
	m_visuals[1] = new BoxVisual(200.0f, 200.0f, sf::Color::Red);
	m_visuals[2] = new BoxVisual(400.0f, 200.0f, sf::Color::Red);
	m_visuals[3] = new BoxVisual(600.0f, 200.0f, sf::Color::Blue);
}

Game::~Game()
{
	// unused
	for (int i = 0; i < m_numOfVisuals; i++)
	{
		delete(m_visuals[i]); // clean up all visuals once Destructor is called.
	}
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
	m_drum.update();

	if (m_drum.m_currentState.leftEdge)
		m_visuals[0]->setToMax();

	if (m_drum.m_currentState.leftMid)
		m_visuals[1]->setToMax();

	if (m_drum.m_currentState.rightMid)
		m_visuals[2]->setToMax();

	if (m_drum.m_currentState.rightEdge)
		m_visuals[3]->setToMax();

	for (int i = 0; i < m_numOfVisuals; i++)
	{
		m_visuals[i]->update(dt);
	}

#ifdef _DEBUG
	if (m_drum.m_currentState.leftEdge)
		std::cout << "Left Edge Hit!" << std::endl;

	if (m_drum.m_currentState.leftMid)
		std::cout << "Left Middle Hit!" << std::endl;

	if (m_drum.m_currentState.rightEdge)
		std::cout << "Right Edge Hit!" << std::endl;

	if (m_drum.m_currentState.rightMid)
		std::cout << "Right Middle Hit!" << std::endl;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (m_drum.isConnected())
		{
			std::cout << "Drum is connected!" << std::endl;
		}
		else
		{
			std::cout << "Drum is NOT connected!" << std::endl;
		}
	}
#endif
}

void Game::render()
{
	m_window.clear(sf::Color::Black);

	// draw game objects
	for (int i = 0; i < m_numOfVisuals; i++)
	{
		m_visuals[i]->render(m_window);
	}

	m_window.display();
}
