#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<cstdlib>
#include <iostream>
#include <string>





class vertex
{
public:
	sf::CircleShape circle;
	vertex();
	void setRadius(float r);
	void setPointCount(float p);
	void setColor(float r, float g, float b);
	void setPosition(float x, float y);
	void setLetter(char c);

	

	


	float radius;
	float pointCount;
	float color[3];
	float position[2];
	char letter;
};

class edge
{
public:
	sf::RectangleShape rectangle;
	edge();
	void setRectSize(float length, float width);
	void setPosition(float x, float y);
	void setColor(float r, float g, float b);
	void setWeight(int w);
	void setRotation(float r);
	float rotation;
	bool isConnectedTo[5];
	float rectSize[2];
	float position[2];
	float color[3];
	int weight;
	std::string weightString;
};

