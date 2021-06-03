#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "king.h"
#include "interactables.h"

using namespace sf;
using namespace std;

class Door
{
public:
	Texture texture;
	Sprite door;
	int frame = 0, row = 0, framecounter = 0;
	void loaddoor();
	void positiondoorclockwise();
	void positiondooranticlockwise();
	void dooranimation();
	void doorclollision(king k, Interactables in);
	Transform transform;
	bool goin=false;
};
