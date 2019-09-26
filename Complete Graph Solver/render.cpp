#include "pch.h"
#include "render.h"
#include "geoObjects.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

using namespace std;

#define INT_MAX 999999
int dp[25][5];

int minimum(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int random[50];

void defineRandom()
{
	for (int i = 0; i < 50; i++)
	{
		random[i] = rand() % 100 + 1;
	}
}



int n = 5;


int VISITED_ALL = (1 << n) - 1;



int  tsp(int mask, int pos, int dist[10][10], int dp[25][5]) 
{
	if (mask == VISITED_ALL) {
		return dist[pos][0];
	}


	if (dp[mask][pos] != -1) {
		return dp[mask][pos];
	}

	
	int ans = INT_MAX;

	
	for (int city = 0; city < n; city++) {

		if ((mask&(1 << city)) == 0) {

			int newAns = dist[pos][city] + tsp(mask | (1 << city), city,dist,dp);
			ans = minimum(ans, newAns);
		}

	}

	return dp[mask][pos] = ans;
}

void drawGraph(sf::RenderWindow& renderWindow)
{
	renderWindow.clear(sf::Color::White);


	defineRandom();
	
	int dist[10][10] = {
		{0,random[0], random[1], random[2], random[3]},
		{random[0],0,random[4],random[5], random[6]},
		{random[1],random[4],0,random[7],random[8]},
		{random[2],random[5],random[7],0,random[9]},
		{random[3],random[6],random[8],random[9],0}
	};

	std::vector<edge> edges(10);

	for (int i = 0; i < 10; i++)
	{
		if ((edges[i].weight) < 1 || (edges[i].weight) > 100)
		{
			edges[i].setWeight(random[i]);
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	string tspDist;
	tspDist = to_string(tsp(1, 0,dist,dp));

	std::vector<vertex> vertices(5);
	

	//positions for k5 complete graph
	std::vector< std::vector<float> > vertexPosition(5, std::vector<float>(5));
	vertexPosition[0][0] = 500;
	vertexPosition[0][1] = 600;
	vertexPosition[1][0] = 900;
	vertexPosition[1][1] = 600;
	vertexPosition[2][0] = 300;
	vertexPosition[2][1] = 200;
	vertexPosition[3][0] = 1100;
	vertexPosition[3][1] = 200;
	vertexPosition[4][0] = 700;
	vertexPosition[4][1] = 0;




	vertices[0].setPosition(vertexPosition[0][0], vertexPosition[0][1]);
	vertices[1].setPosition(vertexPosition[1][0], vertexPosition[1][1]);
	vertices[2].setPosition(vertexPosition[2][0], vertexPosition[2][1]);
	vertices[3].setPosition(vertexPosition[3][0], vertexPosition[3][1]);
	vertices[4].setPosition(vertexPosition[4][0], vertexPosition[4][1]);

	sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf"))
		throw("COULD NOT LOAD FONT");

	std::vector<sf::Text> verticesText(5);
	verticesText.reserve(30);
	for (int i = 0; i < 5; i++)
	{
		std::cout << "The value of i is: " << i << std::endl;
		verticesText[i].setFont(font);
		verticesText[i].setCharacterSize(75);
		verticesText[i].setFillColor(sf::Color::Red);
		verticesText[i].setStyle(sf::Text::Bold);
	}

	verticesText[0].setString("A");
	verticesText[0].setPosition((vertexPosition[0][0]+25), vertexPosition[0][1]);
	verticesText[1].setString("B");
	verticesText[1].setPosition((vertexPosition[1][0]+25), vertexPosition[1][1]);
	verticesText[2].setString("C");
	verticesText[2].setPosition((vertexPosition[2][0] + 25), vertexPosition[2][1]);
	verticesText[3].setString("D");
	verticesText[3].setPosition((vertexPosition[3][0] + 25), vertexPosition[3][1]);
	verticesText[4].setString("E");
	verticesText[4].setPosition((vertexPosition[4][0] + 25), vertexPosition[4][1]);

	


		

	edges[0].setRotation(65);
	edges[0].setPosition(vertexPosition[2][0]+50, vertexPosition[2][1]+25);
	edges[1].setPosition(vertexPosition[0][0]+10, vertexPosition[0][1]+35);
	edges[2].setPosition(vertexPosition[0][0] + 30, vertexPosition[0][1] + 35);
	edges[2].setRotation(290);
	edges[2].setRectSize(600, 20);
	edges[3].setPosition(vertexPosition[0][0] + 10, vertexPosition[0][1] + 75);
	edges[3].setRotation(324);
	edges[3].setRectSize(800, 20);
	edges[4].setPosition(vertexPosition[2][0] + 25, vertexPosition[2][1] + 60);
	edges[4].setRotation(330);
	edges[5].setPosition(vertexPosition[2][0] + 50, vertexPosition[2][1] + 30);
	edges[5].setRotation(35);
	edges[5].setRectSize(750, 20);
	edges[6].setPosition(vertexPosition[2][0]+50, vertexPosition[2][1]+35);
	edges[6].setRectSize(800, 20);
	edges[7].setPosition(vertexPosition[1][0] + 50, vertexPosition[1][1] + 35);
	edges[7].setRotation(295);
	edges[7].setRectSize(450, 20);
	edges[8].setPosition(vertexPosition[1][0] + 50, vertexPosition[1][1] + 35);
	edges[8].setRotation(250);
	edges[8].setRectSize(600, 20);
	edges[9].setPosition(vertexPosition[4][0] + 50, vertexPosition[4][1] + 15);
	edges[9].setRotation(30);
	edges[9].setRectSize(500, 20);
	

	
	std::vector<sf::Text> edgesText(10);
	for (int i = 0; i < 10; i++)
	{
		edgesText[i].setFont(font);
		edgesText[i].setCharacterSize(60);
		edgesText[i].setFillColor(sf::Color::Red);
		edgesText[i].setStyle(sf::Text::Bold);
		edgesText[i].setString(edges[i].weightString);
		
	}
	
	edgesText[0].setPosition(vertexPosition[0][0] - 130, vertexPosition[0][1] - 150);
	edgesText[1].setPosition(vertexPosition[0][0] + 220, vertexPosition[0][1] + 70);
	edgesText[2].setPosition(vertexPosition[0][0] + 60, vertexPosition[0][1] - 250);
	edgesText[2].setRotation(290);
	edgesText[3].setPosition(vertexPosition[0][0] + 250, vertexPosition[0][1] - 175);
	edgesText[3].setRotation(324);
	edgesText[4].setPosition(vertexPosition[2][0] + 200, vertexPosition[2][1]-140);
	edgesText[5].setPosition(vertexPosition[2][0] + 200, vertexPosition[2][1] + 50);
	edgesText[5].setRotation(35);
	edgesText[6].setPosition(vertexPosition[2][0] + 420, vertexPosition[2][1] -30);
	edgesText[7].setPosition(vertexPosition[1][0] + 150, vertexPosition[1][1] -150);
	edgesText[8].setPosition(vertexPosition[1][0] - 140, vertexPosition[1][1] - 300);
	edgesText[9].setPosition(vertexPosition[4][0] + 230, 60);

	


	
	

	


	sf::Text distance;
	distance.setFont(font);
	distance.setCharacterSize(40);
	distance.setFillColor(sf::Color::Red);
	distance.setStyle(sf::Text::Bold);
	distance.setString("The most optimal hamiltonian circuit for A has a cost of " + tspDist);
	distance.setPosition(200, 750);
	renderWindow.draw(distance);
	


	for (int i = 0; i < 10; i++)
	{
		renderWindow.draw((edges[i].rectangle));
		renderWindow.draw((edgesText[i]));
	}

	for (int i = 0; i < 5; i++)
	{
		renderWindow.draw((vertices[i].circle));
		renderWindow.draw(verticesText[i]);
	}

	
	renderWindow.display();



}