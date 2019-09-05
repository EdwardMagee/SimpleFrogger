#include "BoardHazards.h"



BoardHazards::BoardHazards()
{
	if (!car.loadFromFile("./Images/RaceCar.png"))                                      //gets the images from the files 
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	if (!truck.loadFromFile("./Images/Truck.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	if (!log.loadFromFile("./Images/log.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}

	logs.setTexture(log);
	cars.setTexture(car);                                                                //sets the textures onto the sprites  
	trucks.setTexture(truck);

	
	
	
}

sf::Sprite BoardHazards::ResetHazard(sf::Sprite& cars, float x, float y)
{
	 x = cars.getPosition().x;                                                     //gets the x and y of the sprite 
     y = cars.getPosition().y;

		if (cars.getPosition().x > 600) 
		{
			cars.setPosition(sf::Vector2f(x = -50, y));                            //if its higher then x 600 set the x postion to -50
		}
              
		return cars;                                                               // and then return the sprite
	
}

sf::Sprite BoardHazards::ResetHazardTruck(sf::Sprite& trucks, float x, float y)
{
	x = trucks.getPosition().x;
	y = trucks.getPosition().y;

	if (trucks.getPosition().x < -100)              // if the trucks are < -100 then set the new position to 650
	{
		
		trucks.setPosition(sf::Vector2f(x = 650, y));
	}

	return trucks;

}

sf::Sprite BoardHazards::ResetHazardLogs(sf::Sprite& logs, float x, float y)
{
	x = logs.getPosition().x;
	y = logs.getPosition().y;

	if (logs.getPosition().x < -100)                                                 //if the logs go to high or too below the correct x value then 
	{                                                                                //set new x values for them so that they can appear to be reset
		                                                                             //on the other side of the window
		logs.setPosition(sf::Vector2f(x = 610, y));
	}
	if (logs.getPosition().x > 650)
	{
		logs.setPosition(sf::Vector2f(x = -60, y));
	}

	return logs;
}


BoardHazards::~BoardHazards()
{
}
