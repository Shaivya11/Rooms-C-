#include "Level.h"

void Level::LoadTexture() {

	if (texture0.loadFromFile("Data/images/0.jpg") == false) {
		cout << "Not loaded";
	}
	if (texture1.loadFromFile("Data/images/1.jpg") == false) {
		cout << "Not loaded";
	}
	if (texture2.loadFromFile("Data/images/2.jpg") == false) {
		cout << "Not loaded";
	}

	if (texture3.loadFromFile("Data/images/3.jpg") == false) {
		cout << "Not loaded";
	}
	if (texture4.loadFromFile("Data/images/4.jpg") == false) {
		cout << "Not loaded";
	}
	if (texture5.loadFromFile("Data/images/5.jpg") == false) {
		cout << "Not loaded";
	}

	if (texture6.loadFromFile("Data/images/6.jpg") == false) {
		cout << "Not loaded";
	}
	if (texture7.loadFromFile("Data/images/7.jpg") == false) {
		cout << "Not loaded";
	}
	if (texture8.loadFromFile("Data/images/8.jpg") == false) {
		cout << "Not loaded";
	}

	if (texture9.loadFromFile("Data/images/9.jpg") == false) {
		cout << "Not loaded";
	}

	if (texture10.loadFromFile("Data/images/10.jpg") == false) {
		cout << "Not loaded";
	}
}


void Level::loadLevel() {
	int level1[13][13] = { {0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,10,10,10,10,2,10,10,10,10,1,0},
	{0,1,2,7,2,2,2,2,2,7,2,1,0},
	{0,1,2,8,2,2,2,2,2,8,2,1,0},
	{0,1,2,8,2,2,6,2,2,8,2,1,0},
	{0,1,2,9,2,2,2,2,2,9,2,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,1,1,10,10,10,10,10,10,1,1,0},
	{0,0,0,1,1,1,1,1,1,1,0,0,0} };

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			level[i][j] = level1[i][j];
		}
	}

}


void Level::spriteTexture() {

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			if (level[i][j] == 0)
				spritetile[i][j].setTexture(texture0);	
			if (level[i][j] == 1)
				spritetile[i][j].setTexture(texture1);
			if (level[i][j] == 2)
				spritetile[i][j].setTexture(texture2);
			if (level[i][j] == 3)
				spritetile[i][j].setTexture(texture3);
			if (level[i][j] == 4)
				spritetile[i][j].setTexture(texture4);
			if (level[i][j] == 5)
				spritetile[i][j].setTexture(texture5);
			if (level[i][j] == 6)
				spritetile[i][j].setTexture(texture6);
			if (level[i][j] == 7)
				spritetile[i][j].setTexture(texture7);
			if (level[i][j] == 8)
				spritetile[i][j].setTexture(texture8);
			if (level[i][j] == 9)
				spritetile[i][j].setTexture(texture9);
			if (level[i][j] == 10)
				spritetile[i][j].setTexture(texture10);

			spritetile[i][j].setScale(2.0f, 2.0f);
			spritetile[i][j].setOrigin(16, 16);
		}
	}
}
void Level::spritePosition() {

	for (int x = 0; x < 13; x++) {
		for (int y = 0; y < 13; y++) {
			spritetile[x][y].setPosition(x * 64 +32, y * 64+32);
		}
	}
}

void Level::rotateLevelanticlockwise() {
	for (int x = 0; x < 13 / 2; x++) {
		for (int y = x; y < 13 - x - 1; y++) {

			//Store the left value and start the rotation from here
			int temp = level[x][y];

			// Move values from left to top 
			level[x][y] = level[13 - 1 - y][x];

			// Move values from top to right 
			level[13 - 1 - y][x] = level[13 - 1 - x][13 - 1 - y];

			// Move values from right to bottom 
			level[13 - 1 - x][13 - 1 - y] = level[y][13 - 1 - x];

			// Move values from bottom to left 
			level[y][13 - 1 - x] = temp;
		}
	}


	for (int x = 0; x < 13; x++) {
		for (int y = 0; y < 13; y++) {
			spritetile[x][y].setRotation(spritetile[x][y].getRotation()- 90);
		}
	}
}

void Level::rotateLevelclockwise() {

	for (int x = 0; x < 13 / 2; x++) {
		for (int y = x; y < 13 - x - 1; y++) {

			//Store the right value and start the rotation from here
			int temp = level[x][y];

			// Move values from right to top 
			level[x][y] = level[y][13 - 1 - x];

			// Move values from bottom to right 
			level[y][13 - 1 - x] = level[13 - 1 - x][13 - 1 - y];

			// Move values from left to bottom 
			level[13 - 1 - x][13 - 1 - y] = level[13 - 1 - y][x];

			// Assign temp to left 
			level[13 - 1 - y][x] = temp;
		}
	}

	for (int x = 0; x < 13; x++) {
		for (int y = 0; y < 13; y++) {
			spritetile[x][y].setRotation(spritetile[x][y].getRotation() + 90);
		}
	}
}



void Level::initialrotate() {

	for (int x = 0; x < 13; x++) {
		for (int y = 0; y < 13; y++) {
			spritetile[x][y].setRotation(-90);
		}
	}
}



