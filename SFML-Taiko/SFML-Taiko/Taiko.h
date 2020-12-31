#ifndef TAIKO_H
#define TAIKO_H

#include <iostream>
#include <SFML/Graphics.hpp>

struct DrumState
{
	// Left Middle and Outside
	bool leftMid = false;
	bool leftEdge = false;

	// Right Middle and Outside
	bool rightMid = false;
	bool rightEdge = false;
};

class Taiko
{
public:
	Taiko() = delete; // do not use the default constructor
	Taiko(unsigned int& t_controllerNum);

private:
	// The controller number for this Drum
	unsigned int m_controllerNum = 0;
	void isPressed();

public:
	void update();
	inline bool isConnected() const { return sf::Joystick::isConnected(m_controllerNum); };

	DrumState m_currentState;
	DrumState m_previousState;
};

#endif