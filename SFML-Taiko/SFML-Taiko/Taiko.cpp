#include "Taiko.h"

Taiko::Taiko(unsigned int t_controllerNum) : m_controllerNum{t_controllerNum}
{
#ifdef _DEBUG
	std::string msg = sf::Joystick::isConnected(m_controllerNum) ? "Yes" : "No";
	std::cout << "Drum connected: " << msg << std::endl;
#endif
}

void Taiko::isPressed()
{
	if (sf::Joystick::isButtonPressed(0, 6)) // Controller pressed Left Edge
	{
		m_currentState.leftEdge = true;
	}
	else
	{
		m_currentState.leftEdge = false;
	}

	if (sf::Joystick::isButtonPressed(0, 7)) // Controller pressed Right Edge
	{
		m_currentState.rightEdge = true;
	}
	else
	{
		m_currentState.rightEdge = false;
	}

	if (sf::Joystick::isButtonPressed(0, 10)) // Controller pressed Left Middle
	{
		m_currentState.leftMid = true;
	}
	else
	{
		m_currentState.leftMid = false;
	}

	if (sf::Joystick::isButtonPressed(0, 11)) // Controller pressed Right Middle
	{
		m_currentState.rightMid = true;
	}
	else
	{
		m_currentState.rightMid = false;
	}
}

void Taiko::update()
{
	m_previousState = m_currentState; // make the previous state of the drum the current one for this frame
	isPressed();
}
