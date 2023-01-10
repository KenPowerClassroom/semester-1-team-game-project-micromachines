#pragma once
#include <SFML/Graphics.hpp>

class LeaderBoard
{
public:
	LeaderBoard(); 
	void draw(sf::RenderWindow &t_window); 
	void placeCarOnScoreBoard(int t_car);
	void setUpFinalScoreBoards();
private:
	sf::Text m_scoreboard; 
	sf::Font m_font; 

	std::string m_names[5] = { "Red", "Green", "Pink", "Blue", "White" };
	std::string m_place[5] = {"1. ", "2. ", "3. ", "4. ", "5. "};
	bool m_placeFilled[5];
	bool m_carBeenPlace[5];
};
