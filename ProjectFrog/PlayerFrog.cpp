
#include "PlayerFrog.h"



PlayerFrog::PlayerFrog()
{
	if (!frog2.loadFromFile("./Images/Frog2.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	
	if (!frog1.loadFromFile("./Images/Frog.png"))                             // gets the two frog textures from the file
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	
	

	sfrog1.setPosition(sf::Vector2f(300, 375));                              //sets the position of the frog sprite

	if (!winfrog1.loadFromFile("./Images/winfrog.png"))                      //gets the docked from texture
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}


	winsfrog1.setTexture(winfrog1);                                         //sets the texture for the docked frog 

}

sf::Sprite PlayerFrog::FrogAnimation(int& movecounter, sf::Texture& frog1, sf::Texture& frog2,  sf::Sprite& sfrog1)
{
	if (movecounter % 2 != 0)                          //here is used a Modulus, any even number divided by 2 has a remainder of 0  
	{                                                  //by doing a counter based system it can either have 0 or a diffrent remainder 
		sfrog1.setTexture(frog2);                      //so it will change the texture every time 1 counter is added and will turn back when another is added
	}
	
	if (movecounter % 2 == 0)
	{
		
		sfrog1.setTexture(frog1);
	}

	return sfrog1;                                      //return frog will return the new texture
}

PlayerFrog::~PlayerFrog()
{
}
