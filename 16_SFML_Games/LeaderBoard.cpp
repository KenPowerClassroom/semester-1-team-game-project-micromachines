#include "LeaderBoard.h"

LeaderBoard::LeaderBoard()
{
	m_font.loadFromFile("fonts/racing.ttf");

	m_scoreboard.setFont(m_font);
	m_scoreboard.setFillColor(sf::Color::White);
	m_scoreboard.setOutlineThickness(2.5);
	m_scoreboard.setOutlineColor(sf::Color::Black);
	m_scoreboard.setCharacterSize(30u);
	m_scoreboard.setString("Places");
	m_scoreboard.setPosition({ 230, 200 });
}

void LeaderBoard::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_scoreboard);
}

void LeaderBoard::placeCarOnScoreBoard(int t_car)
{
	if (!m_carBeenPlace[t_car])
	{
		for (int i = 0; i < 5; i++)
		{
			if (!m_placeFilled[i])
			{
				m_place[i] = m_place[i] + m_names[t_car];
				m_carBeenPlace[t_car] = true;
				m_placeFilled[i] = true;
				break;
			}
		}
	}
	
}

void LeaderBoard::setUpFinalScoreBoards()
{
	std::string finalScoreBoardText;
	for (int i = 0; i < 5; i++)
	{
		finalScoreBoardText = finalScoreBoardText + m_place[i] + "\n";
	}

	m_scoreboard.setString("Race Places\n" + finalScoreBoardText);
}
