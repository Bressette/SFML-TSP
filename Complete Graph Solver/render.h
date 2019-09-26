#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void drawGraph(sf::RenderWindow& renderWindow);
int  tsp(int mask, int pos, int dist[10][10], int dp[25][5]);
int minimum(int x, int y);
void defineRandom();