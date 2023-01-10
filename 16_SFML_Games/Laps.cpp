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
	textSetUp(); 
}

void Laps::draw(sf::RenderWindow& t_window)
{
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		t_window.draw(m_checpointCircle[i]);
	}
	t_window.draw(m_lapsText);
	
}

void Laps::updatePosition(int t_offsetX, int t_offsetY)
{
	
	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		m_checpointCircle[i].setPosition(lap.getCheckpointX(i) - t_offsetX, lap.getCheckPointY(i) - t_offsetY);
	}
	
}

void Laps::checkForCollision( sf::Vector2f t_carPosition, int &t_currentCheckpoint, int t_car)
{

	int playerCar = 0;

	for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
	{
		if (lap.collisionCheck(t_carPosition.x, t_carPosition.y, i, t_currentCheckpoint))
		{
			if (t_car == playerCar)
			{
				m_checpointCircle[i].setFillColor(Green);
			}
			break; 
		}
	}
	
}

void Laps::checkForCheckpointReset(int& t_currentCheckpoint, int& t_lapsCompleted, int t_car)
{

	int playerCar = 0; 

	if (lap.allcheckPointsPassed(t_currentCheckpoint, t_lapsCompleted))
	{
		if (t_car == playerCar)
		{
			for (int i = 0; i < NUM_OF_CHECKPOINTS; i++)
			{
				m_checpointCircle[i].setFillColor(Red);
			}
		}
	}
}

void Laps::textSetUp()
{

	m_font.loadFromFile("fonts/racing.ttf");

	m_lapsText.setFont(m_font); 
	m_lapsText.setFillColor(sf::Color::White); 
	m_lapsText.setOutlineThickness(2.5);
	m_lapsText.setOutlineColor(sf::Color::Black);
	m_lapsText.setCharacterSize(15u); 
	m_lapsText.setString("Laps");
	m_lapsText.setPosition({ 10, 10 });

}

void Laps::updateText(int t_laps, int t_checkpoints)
{
	m_lapsText.setString("Laps: " + std::to_string(t_laps) + "/3" +
						 "\nCheckpoints: "+ std::to_string(t_checkpoints +1) + "/8");
}



