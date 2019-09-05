#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class BoardHazards
{
public:
	sf::Texture car;
	sf::Texture truck;                     //this contains all the textures and sprites that will become objects within the game
	sf::Texture log;
	sf::Sprite cars;
	sf::Sprite trucks;
	sf::Sprite logs;
	float x, y;                            // these two floats will become the x and y values of the sprites
	


	sf::Sprite BoardHazards::ResetHazard(sf::Sprite& cars, float x, float y);
	sf::Sprite BoardHazards::ResetHazardTruck(sf::Sprite& trucks, float x, float y);           //These functions will reset the position of the sprites
	sf::Sprite BoardHazards::ResetHazardLogs(sf::Sprite& logs, float x, float y);


	BoardHazards();
	~BoardHazards();
};

