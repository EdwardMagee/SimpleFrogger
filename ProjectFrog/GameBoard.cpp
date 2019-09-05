#include "GameBoard.h"



GameBoard::GameBoard()
{
	if (!background.loadFromFile("./Images/background.png"))                   //calls the image within the files
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}

	sbackground.setTexture(background);                                       //sets the texture onto the background 

	sbackground.setPosition(sf::Vector2f(0, 40));                             //sets the position and scale
	sbackground.setScale(sf::Vector2f( 2.7f, 1.67f ));


}


GameBoard::~GameBoard()
{
}
