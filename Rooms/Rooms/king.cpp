#include "king.h"

void king::loadplayer() {
	if (kingtexture.loadFromFile("Data/images/kingspritesheet.png") == false) {
		cout << "Not loaded";
	}

	if (deadtexture.loadFromFile("Data/images/dead.png") == false) {
		cout << "Not loaded";
	}

	if (doorintexture.loadFromFile("Data/images/doorin.png") == false) {
		cout << "Not loaded";
	}

	kingsprite.setTexture(kingtexture);
	kingsprite.setScale(2.0f,2.0f);
	kingsprite.setOrigin(16,16);
	kingsprite.setPosition(170,500);
	row = 0;
}

void king::moveplayer() {

	if (jump == true) {
		yVelocity = -10;
		if (kingsprite.getPosition().y <500) {
			jump = false;
		}
	}

	if (jump == false) {
		yVelocity = 5;
	}


	if (left == true) {
		kingsprite.setScale(-2.0,2.0);
		xVelocity = -5;
	}
	if (right == true) {
		kingsprite.setScale(2.0, 2.0);
		xVelocity = 5;
	}

	if (right == true && left == true) {
		xVelocity = 0;
	}

	if (left == false && right == false) {
		xVelocity = 0;
	}
	kingsprite.move(xVelocity,yVelocity);
}


void king::playercontrol(Event event) {


	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) {
		right = true;
		row = 2;
	}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
		left = true;
		row = 2;
	}

	if (event.type == Event::KeyReleased && event.key.code == Keyboard::Right) {
		right = false;
		row = 0;
	}
	if (event.type == Event::KeyReleased && event.key.code == Keyboard::Left) {
		left = false;
		row = 0;
	}

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
		jump = true;
		row = 1;
	}
	if (event.type == Event::KeyReleased) {
		jump = false;
		row = 0;
	}
}


void king::playeranimation() {
	kingsprite.setTextureRect(IntRect(37 * frame, 32*row, 37, 32));
	if (framecounter == 10) {
		frame = (frame + 1) % 11;
		framecounter = 0;
	}
	framecounter++;
}


