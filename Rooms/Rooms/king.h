#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class king
{
public:
	int frame = 0;
	int row = 0;
	int framecounter = 0;

	Texture kingtexture;
	Sprite kingsprite;

	Texture deadtexture,doorintexture;

	bool right = false;
	bool left = false;
	bool jump = false;
	int xVelocity=5,yVelocity=5;
	void loadplayer();
	void moveplayer();
	void playercontrol(Event event);
	void playeranimation();
};


