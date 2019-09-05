#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <string>

class UserInterface
{
    public:
 
	sf::Font font;                    //this holds the font
	sf::Text tscore;                  //these varaibles will contain the text that displays on the window
	sf::Text texttimer;
	sf::Text tlives;
	sf::Text rightclick;

	sf::Text UserInterface::RightDisplay(sf::Text& rightclick);                        //these functions return vales to the Text varaibles
	sf::Text UserInterface::UpdateUI(sf::Text& tscore, int score);
	sf::Text UserInterface::LivesDisplay(sf::Text& tlives, int lives);
	sf::Text UserInterface::TimeDisplay(sf::Text& texttimer, sf::Time timer);

	UserInterface();
	~UserInterface();
};

