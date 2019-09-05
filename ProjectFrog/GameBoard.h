#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class GameBoard
{
public:
	sf::Texture background;                       //will contain the texture and sprite of the background
	sf::Sprite sbackground;
	

	GameBoard();
	~GameBoard();
};

