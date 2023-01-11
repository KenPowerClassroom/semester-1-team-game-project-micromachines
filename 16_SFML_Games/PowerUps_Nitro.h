#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "Car.h"

class PowerUps_Nitro
{
	public:
		void init();
		void update(float offsetX, float offsetY, newCar& car, sf::Event& event);
		void render(sf::RenderWindow& window);
	private:
		sf::Texture nitroTexture;
		std::vector<sf::Sprite> nitroSprites;

		sf::Sprite nitroIcon;
		sf::RectangleShape nitroRect;
		sf::Font font;
		sf::Text nitroCountText;
		int nitroCount = 0;
		bool boosted = false;

		sf::Texture inkTexture;
		std::vector<sf::Sprite> inkSprites;

		std::vector<bool> consumed;
};