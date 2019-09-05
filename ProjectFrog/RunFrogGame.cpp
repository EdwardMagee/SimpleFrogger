#include "RunFrogGame.h"



RunFrogGame::RunFrogGame()
{

	if (!reset.loadFromFile("./Images/Reset.png")) //gets reset image
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	

	if (!backgroundmusic.openFromFile("./Music/FroggingAbout.wav"))  //gets music file
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}

	
	backgroundmusic.play();     //this plays the background music

	resets.setTexture(reset);   
	resets.setPosition(50, 100);                        //Sets the texture and position of the button
	resetcounter = true;
	

	for (int b = 0; b < 5; b++)  
	{
		wincheck[b] = false;                             //sets all the int bs to false;
	}
	sf::RenderWindow window(sf::VideoMode(600, 400), "Project Frog");                             //creates window
	rect.setSize(sf::Vector2f(600, 335));                                                         //sets the size and position of the two rectangles
	rect.setPosition(0, 65);
	rect2.setSize(sf::Vector2f(600, 110));
	rect2.setPosition(0, 90);                            

	car1.cars.setPosition(200, 340);
	truck1.trucks.setPosition(150, 290);
	car2.cars.setPosition(0, 250);
	car3.cars.setPosition(300, 250);
	truck2.trucks.setPosition(0, 290);
	truck3.trucks.setPosition(350, 290);
	log1[0].logs.setPosition(10, 180);
	log1[1].logs.setPosition(30, 150);
	log1[2].logs.setPosition(50, 125);
	log1[3].logs.setPosition(300, 85);
	log1[4].logs.setPosition(0, 85);
	winfrogdisplay[0].winsfrog1.setPosition(30, 55);
	winfrogdisplay[1].winsfrog1.setPosition(160, 55);
	winfrogdisplay[2].winsfrog1.setPosition(290, 55);
	winfrogdisplay[3].winsfrog1.setPosition(420, 55);
	winfrogdisplay[4].winsfrog1.setPosition(550, 55);	                                 //sets all the objects positions
	 

		while (window.isOpen())
		{	
			window.setFramerateLimit(240);                                                          //had an issue with the speed changing per system this fixed it because it set a limit
			timer = ctimer.getElapsedTime();                                                        //sets the timer value that will be displayed in the ui
			sf::Event event;

			if (!frogobject1.sfrog1.getGlobalBounds().intersects(rect.getGlobalBounds()))           //if the frog intersects with any of the rectangles or objects 
			{
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}
			if (frogobject1.sfrog1.getGlobalBounds().intersects(car1.cars.getGlobalBounds()))
			{
				lives--;                                                                           //Then lose lose a life an reset the frog back to the start
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}
			if (frogobject1.sfrog1.getGlobalBounds().intersects(car2.cars.getGlobalBounds()))
			{
				lives--;
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}
			if (frogobject1.sfrog1.getGlobalBounds().intersects(car3.cars.getGlobalBounds()))
			{
				lives--;
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}
			if (frogobject1.sfrog1.getGlobalBounds().intersects(truck1.trucks.getGlobalBounds()))
			{
				lives--;
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}
			if (frogobject1.sfrog1.getGlobalBounds().intersects(truck2.trucks.getGlobalBounds()))
			{
				lives--;
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}
			if (frogobject1.sfrog1.getGlobalBounds().intersects(truck3.trucks.getGlobalBounds()))
			{
				lives--;
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}
			if (frogobject1.sfrog1.getGlobalBounds().intersects(log1[0].logs.getGlobalBounds()))                          //if the frog is on the log water check becomes false
			{
				frogobject1.sfrog1.move(0.5f, 0.0f);
				watercheck = false;
			}
			else if (frogobject1.sfrog1.getGlobalBounds().intersects(log1[1].logs.getGlobalBounds()))
			{
				frogobject1.sfrog1.move(-0.5f, 0.0f);
				watercheck = false;
			}
			else if (frogobject1.sfrog1.getGlobalBounds().intersects(log1[2].logs.getGlobalBounds()))
			{
				frogobject1.sfrog1.move(0.75f, 00.f);
				watercheck = false;
			}
			else if (frogobject1.sfrog1.getGlobalBounds().intersects(log1[3].logs.getGlobalBounds()))
			{
				frogobject1.sfrog1.move(0.5f, 0.0f);
				watercheck = false;
			}
			else if (frogobject1.sfrog1.getGlobalBounds().intersects(log1[4].logs.getGlobalBounds()))
			{
				frogobject1.sfrog1.move(0.5f, 0.0f);
				watercheck = false;
			}
			else                                                                    //If frog is not on the log it becomes true and will reset the position of the frog
			{
				watercheck = true;
			}

			for (int a = 0; a < 5; a++)       
			{
				if ((wincheck[a] == false) && (frogobject1.sfrog1.getGlobalBounds().intersects(winfrogdisplay[a].winsfrog1.getGlobalBounds())))
				{
					score += 1000;                                        //if wincheck == false then do the following int changes and set it to true so it cant be done again
					wincountercheck++;        
					lives++;
					frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
					wincheck[a] = true;

				}
			}

			if (frogobject1.sfrog1.getGlobalBounds().intersects(rect2.getGlobalBounds()) && watercheck == true)     //what happens when the frog touches water
			{
				lives--;
				frogobject1.sfrog1.setPosition(sf::Vector2f(300, 375));
			}

			if (lives == 0 || wincountercheck == 5)               //Game over will happen of any of these two happen 
			{
				window.close();
				overcheck = true;
				resetcounter = false;                             // the window will close and the bools will change, overcheck opens the second window
			}

			while (window.pollEvent(event))
			{


				switch (event.type)                                //the player can create a game over by clicking the x
				{
				case sf::Event::Closed:
					window.close();
					resetcounter = false;
					overcheck = true;


				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))                              //allows the user to control the movment of the frog
				{
					score = score + 10;
					movecounter++;
					frogobject1.sfrog1.move(0, -10);

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					score = score - 10;
					movecounter++;
					frogobject1.sfrog1.move(0, 10);

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					movecounter++;
					frogobject1.sfrog1.move(-10, 0);

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					frogobject1.sfrog1.move(10, 0);
					movecounter++;
				}



			}

			car3.cars.move(0.6f, 0.0f );                                                    // moves all the objects 
			car2.cars.move(0.6f, 0.0f);
			car1.cars.move(1.2f, 0.0f);
			truck1.trucks.move(-0.6f, 0.0f);
			truck2.trucks.move(-0.6f, 0.0f);
			truck3.trucks.move(-0.6f, 0.0f);
			log1[0].logs.move(0.5f, 0.0f);
			log1[1].logs.move(-0.5f, 0.0f);
			log1[2].logs.move(0.75f, 0.0f);
			log1[3].logs.move(0.5f, 0.0f);
			log1[4].logs.move(0.5f, 0.0f);

			window.clear();

			window.draw(backgroundobject.sbackground);                                      //draws all the objects 
			window.draw(ui1.UpdateUI(ui1.tscore, score));
			window.draw(ui1.LivesDisplay(ui1.tlives, lives));
			window.draw(ui1.TimeDisplay(ui1.texttimer, timer));
			window.draw(car1.ResetHazard(car1.cars, car1.x, car1.y));
			window.draw(car2.ResetHazard(car2.cars, car2.x, car2.y));
			window.draw(car3.ResetHazard(car3.cars, car3.x, car3.y));
			window.draw(truck1.ResetHazardTruck(truck1.trucks, truck1.x, truck1.y));
			window.draw(truck2.ResetHazardTruck(truck2.trucks, truck2.x, truck2.y));
			window.draw(truck3.ResetHazardTruck(truck3.trucks, truck3.x, truck3.y));

			for (int i = 0; i < 5; i++)                                                      //wanted to try making for loop arrays to display mutiple objects
			{
				window.draw(log1[i].ResetHazardLogs(log1[i].logs, log1[i].x, log1[i].y));
			}
			for (int i = 0; i < 5; i++)
			{

				if (wincheck[i] == true)                                                 //added a boolean so that when it becomes true the docked frogs will display
				{
					window.draw(winfrogdisplay[i].winsfrog1);
				}
			}
			window.draw(frogobject1.FrogAnimation(movecounter, frogobject1.frog1, frogobject1.frog2, frogobject1.sfrog1)); //draws the frog

			window.display();
			
			
		}
          
		if (overcheck == true) {
			sf::Event event2;
			sf::RenderWindow window2(sf::VideoMode(600, 200), "GAME OVER");                //second window to display game results 
			while (window2.isOpen())
			{


				window2.clear();

				window2.draw(ui1.UpdateUI(ui1.tscore, score));
				window2.draw(ui1.TimeDisplay(ui1.texttimer, timer));
				window2.draw(resets);
				window2.draw(ui1.RightDisplay(ui1.rightclick));
				window2.display();                                                    //draws eveything that is displayed in window 2


				if (sf::Mouse::isButtonPressed(sf::Mouse::Right))                     //when right mouse is pressed 
				{
					
					resetcounter = true;
					overcheck = false;
					window2.close();

				}

				while (window2.pollEvent(event2))
				{


					switch (event2.type)                                              //when x is pressed it will set them both false and end the game
					{

					case sf::Event::Closed:
						window2.close();
						resetcounter = false;
						overcheck = false;
						break;

					}
				}

			}

		}
}





RunFrogGame::~RunFrogGame()
{

}
