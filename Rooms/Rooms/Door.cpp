#include "Door.h"
#include "king.h"

void Door::loaddoor() {

	if (texture.loadFromFile("Data/images/door.png") == false) {
		cout << "Not loaded";
	}

	door.setTexture(texture);
	door.setScale(2.0f, 2.0f);
	door.setOrigin(20,-88);
	door.setPosition(416,416);
	door.setRotation(180);
	row = 0;
}

void Door::dooranimation() {

		door.setTextureRect(IntRect(46 * frame, 56 * row, 46, 56));
		if (framecounter == 10) {
			frame = (frame + 1) % 5;
			framecounter = 0;
		}
		framecounter++;

}

void Door::positiondoorclockwise() {
	
	door.setRotation(door.getRotation()+90);
}

void Door::positiondooranticlockwise() {

	door.setRotation(door.getRotation()-90);
}

void Door::doorclollision(king k, Interactables in) {
	if (door.getGlobalBounds().intersects(k.kingsprite.getGlobalBounds()) == true && row==0 && in.deletecoin==true) {
		row = 1;
		if (row == 1) {
			dooranimation();
		}
		row = 2;
		goin = true;
	}
}
