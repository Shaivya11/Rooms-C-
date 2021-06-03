#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "king.h"

using namespace sf;
using namespace std;

class Interactables
{
public:
	Texture box_texture, bomb_texture, coin_texture;
	Sprite box, bomb, coin;

	int framecounter = 0,frame=0,row=0;

	bool deletecoin=false;

	void loadInteractables();
	void interactablesanimation();
	void coincollision(king king);
	void bombcollision(king king);
	void boxmove();

	int x = 0, y = 5;

	bool dead = false;
};

