#include "pch.h"
#include "geoObjects.h"
#include <stdlib.h>
#include <time.h>


//functions of the vertex class
void vertex::setRadius(float r)
{
	radius = r;
	circle.setRadius(radius);
}

void vertex::setPointCount(float p)
{
	pointCount = p;
	circle.setPointCount(pointCount);
}

void vertex::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	circle.setFillColor(sf::Color(color[0], color[1], color[2]));
}

void vertex::setPosition(float x, float y)
{
	position[0] = x;
	position[1] = y;
	circle.setPosition(position[0], position[1]);
}

void vertex::setLetter(char c)
{
	letter = c;
}


vertex::vertex()
{
	setRadius(50);
	setPointCount(100);
	setColor(0, 0, 0);
	setPosition(50, 50);
}



//functions of the edge class
void edge::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	rectangle.setFillColor(sf::Color(color[0], color[1], color[2]));
}

void edge::setPosition(float x, float y)
{
	position[0] = x;
	position[1] = y;
	rectangle.setPosition(position[0], position[1]);
}

void edge::setRectSize(float length, float width)
{
	rectSize[0] = length;
	rectSize[1] = width;
	rectangle.setSize(sf::Vector2f(length, width));
}

void edge::setWeight(int w)
{
	weight = w;
	weightString = std::to_string(weight);
}

void edge::setRotation(float r)
{
	rotation = r;
	rectangle.setRotation(r);
}
edge::edge()
{
	setColor(0, 0, 0);
	setPosition(0, 0);
	setRectSize(450, 20);
	setWeight(0);
}

