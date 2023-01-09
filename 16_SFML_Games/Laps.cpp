#include "Laps.h"

Laps::Laps()
{
	Red.a = 50;
	Green.a = 50; 
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
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
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		t_window.draw(m_checpointCircle[i]);
	}
	
}

void Laps::updatePosition(int t_offsetX, int t_offsetY)
{
	
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		m_checpointCircle[i].setPosition(elLapo.getX(i) - t_offsetX, elLapo.getY(i) - t_offsetY);
	}
	
}

void Laps::checkForCollision( sf::Vector2f t_carPosition)
{
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		if (elLapo.collisionCheck(t_carPosition.x, t_carPosition.y, i))
		{
			m_checpointCircle[i].setFillColor(Green); 
		}
	}
}

void Laps::checkForCheckpointReset()
{
	int checkPointsPassed = 0;
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		if (m_checpointCircle[i].getFillColor() == Green)
		{
			checkPointsPassed++; 
		}
	}
	if (checkPointsPassed == NUM_OF_CHECKPOINTS)
	{
		for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
		{
			m_checpointCircle[i].setFillColor(Red);
			
		}
	}
	
}



