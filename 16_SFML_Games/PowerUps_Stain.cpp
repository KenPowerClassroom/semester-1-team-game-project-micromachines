#include "PowerUps_Stain.h"

void PowerUps_Stain::init()
{
	if (!inkTexture.loadFromFile("images/racing/ink.png"))
	{
		// Error
	}

	for (int i = 0; i < 2; i++)
	{
		sf::Sprite ink;
		ink.setTexture(inkTexture);
		ink.setScale(.1f, .1f);
		inkSprites.push_back(ink);

		consumed.push_back(false);
	}

	inkIcon.setTexture(inkTexture);
	inkIcon.setScale(.3f, .3f);
	inkIcon.setPosition(-2000.0f, -2000.0f);

	inkRect.setFillColor(sf::Color::Black);
	inkRect.setSize(sf::Vector2f(inkIcon.getGlobalBounds().width + 20.0f, inkIcon.getGlobalBounds().height));
	inkRect.setPosition(-2000.0f, -2000.0f);

	if (!font.loadFromFile("fonts/racing.ttf"))
	{
		// Error
	}

	inkCountText.setFont(font);
	inkCountText.setCharacterSize(24);
	inkCountText.setFillColor(sf::Color::White);
	inkCountText.setPosition(-2000.0f, -2000.0f);

	if (!stainTexture.loadFromFile("images/racing/stain.png"))
	{
		// Error
	}

	for (int i = 0; i < 10; i++)
	{
		sf::Sprite stain;
		stain.setTexture(stainTexture);
		stain.setScale(.2f, .2f);
		stain.setPosition(-5000.0f, -5000.0f);
		stainSprites.push_back(stain);
		stainPositions.push_back({ -5000.0f, -5000.0f });
	}
}

void PowerUps_Stain::update(float offsetX, float offsetY, std::vector<newCar>& cars, sf::Event& event)
{
	if (!consumed[0])
		inkSprites[0].setPosition(1375.0f - offsetX, 1600.0f - offsetY);

	if (!consumed[1])
		inkSprites[1].setPosition(2550.0f - offsetX, 2550.0f - offsetY);

	for (int i = 0; i < inkSprites.size(); i++)
	{
		if (inkSprites[i].getGlobalBounds().intersects(cars[0].getSprite().getGlobalBounds()))
		{
			inkSprites[i].setPosition(-200.0f, -200.0f);
			inkIcon.setPosition(320.0f, .0f);
			inkRect.setPosition(310.0f, .0f);
			inkCountText.setPosition(310.0f, .0f);
			inkCount++;
			consumed[i] = true;
		}
	}

	inkCountText.setString("x" + std::to_string(inkCount));

	if (inkCount > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			if (!spilled)
			{
				stainPositions[stainIndex].x = cars[0].getPosition().x;
				stainPositions[stainIndex].y = cars[0].getPosition().y;

				stainSprites[stainIndex].setPosition(stainPositions[stainIndex].x - offsetX, stainPositions[stainIndex].y - offsetY);
				stainIndex++;
				inkCount--;
				spilled = true;
			}
		}

		if (sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::E)
				spilled = false;
		}
	}
	else
	{
		inkIcon.setPosition(-2000.0f, -2000.0f);
		inkRect.setPosition(-2000.0f, -2000.0f);
		inkCountText.setPosition(-2000.0f, -2000.0f);
	}

	for (int i = positionIndex; i < stainPositions.size(); i++)
	{
		stainSprites[i].setPosition(stainPositions[i].x - offsetX, stainPositions[i].y - offsetY);
	}

	for (int i = 1; i < cars.size(); i++)
	{
		for (int j = 0; j < stainSprites.size(); j++)
		{
			if (cars[i].getSprite().getGlobalBounds().intersects(stainSprites[j].getGlobalBounds()))
			{
				cars[i].slowDown();
				stainSprites[j].setPosition(-5000.0f, -5000.0f);
				positionIndex++;
			}
		}
	}
}

void PowerUps_Stain::render(sf::RenderWindow& window)
{
	for (int i = 0; i < inkSprites.size(); i++)
	{
		window.draw(inkSprites[i]);
	}

	for (int i = 0; i < stainSprites.size(); i++)
	{
		window.draw(stainSprites[i]);
	}

	window.draw(inkRect);
	window.draw(inkCountText);
	window.draw(inkIcon);
}
