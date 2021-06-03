#include "collision.h"

void collision::loaddoor() {

	if (doortexture.loadFromFile("Data/images/door.png") == false) {
		cout << "Not loaded";
	}

	door.setTexture(doortexture);
	door.setScale(2.0f, 2.0f);
	door.setOrigin(23, 28);
	door.setPosition(400,120);
	door.setRotation(180);
}

void collision::dooranimation() {

	door.setTextureRect(IntRect(46 * frame, 56 * row, 46, 56));
	if (framecounter == 10) {
		frame = (frame + 1) % 5;
		framecounter = 0;
	}
	framecounter++;
}

void collision::positiondoorclockwise() {
	
	transform.rotate(90, { 416,416 });
}

void collision::positiondooranticlockwise() {

	transform.rotate(-90, { 416,416 });
}



