#ifndef BOX_VISUAL
#define BOX_VISUAL

#include <iostream>
#include <SFML/Graphics.hpp>

class BoxVisual
{
public:
	BoxVisual() = delete; // Do not use default constructor
	BoxVisual(float t_leftPos, float t_width, sf::Color t_boxCol);

private:
	sf::RectangleShape m_body;
	
	const sf::Color c_BLACK{ 0, 0, 0, 255 };
	sf::Color m_initialCol;
	
	float m_fadeRate{ 2.0f };

public:
	void update(sf::Time& dt);
	void render(sf::RenderWindow& t_window) const;
	void setToMax(); // Set the Box Visual to max of it's Color
};

#endif