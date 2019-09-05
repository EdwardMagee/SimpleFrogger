#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class PlayerFrog
{
public:

	sf::Texture frog1;                   //two textrues to swap between 
	sf::Texture frog2;
	sf::Sprite sfrog1;                   //the main frog sprite
	sf::Texture winfrog1;
	sf::Sprite winsfrog1;                //the docked frog sprite and texture 
	

	sf::Sprite PlayerFrog::FrogAnimation(int& movecounter, sf::Texture& frog1, sf::Texture& frog2,  sf::Sprite& sfrog1);

	PlayerFrog();                                                                  //the function changes the texture of the frog
	~PlayerFrog();
};

