#include "Laps.h"

Laps::Laps()
{
	Red.a = 50;
	Green.a = 50; 
	for (int i = 0; i < num; i++)
	{
		m_checpointCircle[i].setFillColor(Red );
		m_checpointCircle[i].setRadius(100); 
		m_checpointCircle[i].setPosition({-200,200});
		m_checpointCircle[i].setOutlineThickness(2);
		m_checpointCircle[i].setOutlineColor(sf::Color::Black); 
	}
}

void Laps::draw(sf::RenderWindow& t_window)
{
	for (int i = 0; i < num; i++)
	{
		t_window.draw(m_checpointCircle[i]);
	}
	
}

void Laps::updatePosition(int t_offsetX, int t_offsetY)
{
	
	for (int i = 0; i < num; i++)
	{
		m_checpointCircle[i].setPosition(points[i].x - t_offsetX, points[i].y - t_offsetY);
	}
	
}

void Laps::checkForCollision(sf::Sprite t_playerCar)
{
	for (int i = 0; i < num; i++)
	{
		if (m_checpointCircle[i].getGlobalBounds().intersects(t_playerCar.getGlobalBounds()))
		{
			m_checpointCircle[i].setFillColor(Green); 
		}
	}
}

bool Laps::getColorOfFirstCheckpoint(int t_checkpoint)
{
	if (m_checpointCircle[t_checkpoint].getFillColor() == Green)
	{
		return true; 
	}
	return false;
}


