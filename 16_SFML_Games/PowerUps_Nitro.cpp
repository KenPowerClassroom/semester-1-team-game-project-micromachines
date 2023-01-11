#include "PowerUps_Nitro.h"

void PowerUps_Nitro::init()
{
	if (!nitroTexture.loadFromFile("images/racing/nitro.png"))
	{
		// Error
	}

	for (int i = 0; i < 3; i++)
	{
		sf::Sprite nitro;
		nitro.setTexture(nitroTexture);
		nitro.setScale(.1f, .1f);
		nitroSprites.push_back(nitro);

		consumed.push_back(false);
	}

	nitroIcon.setTexture(nitroTexture);
	nitroIcon.setScale(.1f, .1f);
	nitroIcon.setPosition(-2000.0f, -2000.0f);

	nitroRect.setFillColor(sf::Color::Black);
	nitroRect.setSize(sf::Vector2f(nitroIcon.getGlobalBounds().width, nitroIcon.getGlobalBounds().height));
	nitroRect.setPosition(-2000.0f, -2000.0f);
	
	if (!font.loadFromFile("fonts/racing.ttf"))
	{
		// Error
	}

	nitroCountText.setFont(font);
	nitroCountText.setCharacterSize(12);
	nitroCountText.setFillColor(sf::Color::White);
	nitroCountText.setPosition(-2000.0f, -2000.0f);

	inputText.setFont(font);
	inputText.setCharacterSize(12);
	inputText.setFillColor(sf::Color::Black);
	inputText.setPosition(-2000.0f, -2000.0f);
	inputText.setString("Press\nSpace");
}

void PowerUps_Nitro::update(float offsetX, float offsetY, newCar& car, sf::Event& event)
{
	if(!consumed[0])
		nitroSprites[0].setPosition(700.0f - offsetX, 414.0f - offsetY);

	if (!consumed[1])
		nitroSprites[1].setPosition(1913.0f - offsetX, 2155.0f - offsetY);

	if (!consumed[2])
		nitroSprites[2].setPosition(1895.0f - offsetX, 3294.0f - offsetY);

	for (int i = 0; i < nitroSprites.size(); i++)
	{
		if (nitroSprites[i].getGlobalBounds().intersects(car.getSprite().getGlobalBounds()))
		{
			nitroSprites[i].setPosition(-200.0f, -200.0f);
			nitroIcon.setPosition(575.0f, .0f);
			nitroRect.setPosition(575.0f, .0f);
			nitroCountText.setPosition(575.0f, .0f);
			inputText.setPosition(575.0f, 50.0f);
			nitroCount++;
			consumed[i] = true;
		}
	}

	nitroCountText.setString("x" + std::to_string(nitroCount));

	if (nitroCount > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!boosted)
			{
				car.nitroBoost();
				nitroCount--;
				boosted = true;
			}
		}

		if (sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Space)
				boosted = false;
		}
	}
	else
	{
		nitroIcon.setPosition(-2000.0f, -2000.0f);
		nitroRect.setPosition(-2000.0f, -2000.0f);
		nitroCountText.setPosition(-2000.0f, -2000.0f);
		inputText.setPosition(-2000.0f, -2000.0f);
	}
}

void PowerUps_Nitro::render(sf::RenderWindow& window)
{
	for (int i = 0; i < nitroSprites.size(); i++)
	{
		window.draw(nitroSprites[i]);
	}

	window.draw(nitroRect);
	window.draw(nitroCountText);
	window.draw(nitroIcon);
	window.draw(inputText);
}
