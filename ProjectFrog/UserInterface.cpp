#include "UserInterface.h"



UserInterface::UserInterface()
{
	if (!font.loadFromFile("./Fonts/ArialTh.ttf"))                      //gets font from file
	{
		std::cout << "Failed to get Font" << std::endl;
	}
 
	tscore.setFont(font);                         //sets font 
	texttimer.setFont(font);
	tlives.setFont(font);
	rightclick.setFont(font);
	tscore.setPosition(420, 0);                  //sets the position of the text
	tlives.setPosition(320, 0);
	rightclick.setPosition(0, 50);
	
}

sf::Text UserInterface::UpdateUI(sf::Text &tscore, int score)                                   //when score is added its passed into this function
{                                                                                               //it converts that into a string and then that string 
	std::string sscore = "Score: " + std::to_string(score);                                     //is set to the text tscore allowing for it to be displayed
	tscore.setString(sscore);
	return tscore;
}

sf::Text UserInterface::LivesDisplay(sf::Text& tlives, int lives)                                //passes int lives and converts it to a string so that it
{																								 //may be set into the text varaible
	std::string slives = "Lives -" + std::to_string(lives) + "- ";
	tlives.setString(slives);
	return tlives;
}

sf::Text UserInterface::TimeDisplay(sf::Text &texttimer, sf::Time timer)                     //Time is passed, time is set to a float, that float becomes a string 
{																							 //Then that string is set into a text varaible
	int tcounter = timer.asSeconds();
    std::string tscore = "Time: " + std::to_string(tcounter);
	texttimer.setString(tscore);
	return texttimer;
}

sf::Text UserInterface::RightDisplay(sf::Text& rightclick)                                   //sets the text for righclick
{
	rightclick.setString("Click The Right Mouse Key To Reset");
	return rightclick;
}

UserInterface::~UserInterface()
{
}
