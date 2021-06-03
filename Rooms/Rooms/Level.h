#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Level
{
public:

	Texture texture0, texture1, texture2, texture3, texture4, texture5,
		texture6, texture7, texture8, texture9, texture10, texture11,
		texture12, texture13, texture14, texture15, texture16, texture17,
		texture18, texture19, texture20, texture21, texture22, texture23,
		texture24, texture25, texture26;
	int level[13][13];
	Sprite spritetile[13][13];
	void LoadTexture();
	void spriteTexture();
	void spritePosition();
	void loadLevel();
	void rotateLevelanticlockwise();
	void rotateLevelclockwise();
	void initialrotate();

};

