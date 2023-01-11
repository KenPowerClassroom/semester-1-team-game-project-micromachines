#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "Car.h"

class PowerUps_Stain
{
public:
	void init();
	void update(float offsetX, float offsetY, std::vector<newCar>& cars, sf::Event& event);
	void render(sf::RenderWindow& window);
private:
	sf::Texture inkTexture;
	std::vector<sf::Sprite> inkSprites;

	sf::Sprite inkIcon;
	sf::RectangleShape inkRect;
	sf::Font font;
	sf::Text inkCountText;
	int inkCount = 0;
	bool spilled = false;

	std::vector<bool> consumed;

	sf::Texture stainTexture;
	std::vector<sf::Sprite> stainSprites;
	int stainIndex = 0;
	std::vector<sf::Vector2f> stainPositions;
	int positionIndex = 0;

	sf::Text inputText;
};