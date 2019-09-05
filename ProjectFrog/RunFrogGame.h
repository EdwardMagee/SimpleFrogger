#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "PlayerFrog.h"
#include "UserInterface.h"
#include "GameBoard.h"
#include "BoardHazards.h"
#include <SFML\Audio.hpp>                                                //#include SFML Audio, Graphics and all of my other classes  

class RunFrogGame
{
public:
	bool resetcounter;											//To check for reset
	bool watercheck;													//to check if frog is in water
	bool wincheck[5];													//check if all frogs are docked
	bool overcheck;                                             //bool for second window
	int movecounter = 2;                                                //counter for move animation
	int score = 0;                                                      //contains score
	int lives = 3;                                                      //lives
	int wincountercheck = 0;                                            //counter to check win                               

	GameBoard backgroundobject;										    //All the objects used to create the game graphics
	PlayerFrog frogobject1;
	PlayerFrog winfrogdisplay[5];
	UserInterface ui1;
	BoardHazards car1;
	BoardHazards car2;
	BoardHazards car3;
	BoardHazards truck1;
	BoardHazards truck2;
	BoardHazards truck3;
	BoardHazards log1[5];
	
	sf::Music backgroundmusic;                                                          //music that plays
	sf::Clock ctimer;																    //created to display a time to the user
	sf::Time timer;
	sf::RectangleShape rect;															//rectangle around window
	sf::RectangleShape rect2;                                                           //rectangle around water 
	sf::Texture reset;                                                                  //reset button texture and sprite
	sf::Sprite resets;

	RunFrogGame();

	~RunFrogGame();
};

