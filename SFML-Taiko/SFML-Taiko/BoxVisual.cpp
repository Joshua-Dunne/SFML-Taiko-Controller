#include "BoxVisual.h"

BoxVisual::BoxVisual(float t_leftPos, float t_width, sf::Color t_boxCol) : m_initialCol(t_boxCol)
{
	m_body.setFillColor(c_BLACK);
	m_body.setPosition(sf::Vector2f{ t_leftPos,0 }); // we do not set origin for visual
	m_body.setSize(sf::Vector2f{ t_width, 600.0f }); // assuming screen height is 600.0f
}

void BoxVisual::update(sf::Time& dt)
{
	if (m_body.getFillColor() != c_BLACK) // as long as the color is not pure black
	{
		// gradually decrease all values by fade rate
		m_body.setFillColor(m_body.getFillColor() - sf::Color{ 
			m_fadeRate,
			m_fadeRate,
			m_fadeRate,
			0 }); // do not change alpha value
	}
}

void BoxVisual::render(sf::RenderWindow& t_window) const
{
	t_window.draw(m_body);
}

void BoxVisual::setToMax()
{
	m_body.setFillColor(m_initialCol);
}
