#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "BaseEntity.h"
#include "UtilRandom.h"
#include "SteeringAgent.h"

#include "Nodes.h"

int main()
{
	// construct a window that uses a resolution of 800 x 600
	sf::RenderWindow window(sf::VideoMode(800, 600), "AI Framework");

	// because we're running as a console application, we still get access to the console, so can use std::cout to print to it
	std::cout << "Constructed SFML Window" << std::endl;

	// construct 5 base entities
	/*for (int i = 0; i < 5; i++) 
	{
		SteeringAgent *boid = new SteeringAgent();
	}*/

	Nodes* grid[5][5];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Nodes* node = new Nodes();
			node->x = i;
			node->y = j;
			node->size = 64;
			node->Initialize();
			grid[i][j] = node;
		}
	}

	// our game loop
	while (window.isOpen())
	{
		// poll for events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					for (auto entity : BaseEntity::Renderables)
					{
						entity->setPosition(400, 300);
					}
				}
			}
		}

		// clear the window before drawing anything to it
		window.clear();
		
		// update all our entities
		for ( auto entity : BaseEntity::Renderables )
		{
			entity->Think();
		}

		// and then draw them
		for (auto entity : BaseEntity::Renderables)
		{
			window.draw(entity->GetSprite(), entity->getTransform());
		}

		// swap the frame buffers
		window.display();
	}

	return 0;
}
