#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include <vector>


class GameWorld
{
	Vector2i exitPos;
	vector<Vector2i> enemyPos;
	Vector2i playerPos;
	void setUpInintialState();
	void setUpEnemyPositions();
	void setUpTiles();
public:
	vector<vector<Level*>>tiles;
	int gridLength;
	GameWorld();
};

