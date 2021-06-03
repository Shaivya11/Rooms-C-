#include "Interactables.h"

void Interactables::loadInteractables() {

	if (box_texture.loadFromFile("Data/images/box.png") == false) {
		cout << "Not loaded";
	}

	if (coin_texture.loadFromFile("Data/images/coin.png") == false) {
		cout << "Not loaded";
	}

	if (bomb_texture.loadFromFile("Data/images/bomb.png") == false) {
		cout << "Not loaded";
	}

	

	box.setTexture(box_texture);
	box.setScale(4.0f, 4.5f);
	box.setOrigin(11,8);
	box.setPosition(400, 200);

	bomb.setTexture(bomb_texture);
	bomb.setScale(2.0f, 2.0f);
	bomb.setOrigin(13,12);
	bomb.setPosition(0,0);

	coin.setTexture(coin_texture);
	coin.setScale(2.0f, 2.0f);
	coin.setOrigin(9, 7);
	coin.setPosition(650, 670);
}

void Interactables::interactablesanimation() {

	coin.setTextureRect(IntRect(18 * frame, 14 * row, 18, 14));
	if (framecounter == 10) {
		frame = (frame + 1) % 10;
		framecounter = 0;
	}
	framecounter++;

	bomb.setTextureRect(IntRect(26 * frame, 24 * row, 26, 24));
	if (framecounter == 10) {
		frame = (frame + 1) % 4;
		framecounter = 0;
	}
	framecounter++;
}



void Interactables::coincollision(king king) {

	if (coin.getGlobalBounds().intersects(king.kingsprite.getGlobalBounds()) == true) {
		deletecoin = true;
	}
}

void Interactables::bombcollision(king king) {

	if (bomb.getGlobalBounds().intersects(king.kingsprite.getGlobalBounds()) == true) {
		dead = true;
	}
}

void Interactables::boxmove() {
	box.move(x, y);
}