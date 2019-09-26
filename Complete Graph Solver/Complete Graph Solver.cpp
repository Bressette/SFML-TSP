#include "pch.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "geoObjects.h"
#include "render.h"

using namespace std;




int main()
{
	srand(time(0));
	bool wait = false;
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "My window");
	
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				wait = false;
				break;



			}

		}


		while (!wait)
		{
			drawGraph(window);
			wait = true;
		}
			
		}

		

		return 0;
	

}
