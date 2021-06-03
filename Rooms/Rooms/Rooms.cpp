#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Level.h"
#include "king.h"
#include "Door.h"
#include "Interactables.h"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(832,832),"Rooms");
	window.setFramerateLimit(60);

	Door d;
	d.loaddoor();

	Level l;
	l.loadLevel();
	l.LoadTexture();

	l.spriteTexture();
	l.spritePosition();
	l.initialrotate();

	l.rotateLevelclockwise();
	l.spriteTexture();
	l.spritePosition();

	king k;
	k.loadplayer();

	Interactables interact;
	interact.loadInteractables();

	while (window.isOpen()) {
	
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::D) {
				l.rotateLevelclockwise();
				l.spriteTexture();
				l.spritePosition();
				d.positiondoorclockwise();
				k.kingsprite.setPosition(k.kingsprite.getPosition().x, 600);
				interact.box.setPosition(interact.box.getPosition().x, 600);
				
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::A) {
				l.rotateLevelanticlockwise();
				l.spriteTexture();
				l.spritePosition();
				d.positiondooranticlockwise();
				k.kingsprite.setPosition(k.kingsprite.getPosition().x, 600);
				interact.box.setPosition(interact.box.getPosition().x, 600);
			
			}


			k.playercontrol(event);
		}


		if (interact.dead == true) {
			l.loadLevel();
			l.LoadTexture();
			l.spriteTexture();
			l.spritePosition();
			l.initialrotate();

			l.rotateLevelclockwise();
			l.spriteTexture();
			l.spritePosition();
			k.loadplayer();
			interact.loadInteractables();
			d.loaddoor();
			interact.deletecoin = false;
			interact.dead = false;
		}

		else if (d.goin == true) {
			k.row = 3;
			if (k.row == 3) {
				k.playeranimation();
			}
			//wait
			d.goin = false;
	
			l.loadLevel();
			l.LoadTexture();
			l.spriteTexture();
			l.spritePosition();
			l.initialrotate();

			l.rotateLevelclockwise();
			l.spriteTexture();
			l.spritePosition();
			k.loadplayer();
			interact.loadInteractables();
			d.loaddoor();
			interact.deletecoin = false;
			interact.dead = false;
		}

		else {
			k.playeranimation();
		}

		d.dooranimation();
		interact.interactablesanimation();
		k.moveplayer();
		interact.boxmove();


		if (interact.box.getGlobalBounds().intersects(k.kingsprite.getGlobalBounds()) == true) {
			k.kingsprite.move(0, -k.yVelocity);
		}

		if (interact.box.getGlobalBounds().intersects(k.kingsprite.getGlobalBounds()) == true) {
			k.kingsprite.move(-k.xVelocity, 0);
			if (k.right == true) {
				interact.box.move(5, 0);
			}
			if (k.left == true) {
				interact.box.move(-5, 0);
			}
		}


	for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {

				if (l.spritetile[i][j].getGlobalBounds().intersects(k.kingsprite.getGlobalBounds()) == true) {
					if (l.spritetile[i][j].getTexture() == &l.texture1 || l.spritetile[i][j].getTexture() == &l.texture3 || l.spritetile[i][j].getTexture() == &l.texture4 || l.spritetile[i][j].getTexture() == &l.texture5 || l.spritetile[i][j].getTexture() == &l.texture6) {
						k.kingsprite.move(0, -k.yVelocity);
					}
				}

				if (l.spritetile[i][j].getGlobalBounds().intersects(k.kingsprite.getGlobalBounds()) == true) {
					if (l.spritetile[i][j].getTexture() == &l.texture1 || l.spritetile[i][j].getTexture() == &l.texture3 || l.spritetile[i][j].getTexture() == &l.texture4 || l.spritetile[i][j].getTexture() == &l.texture5 || l.spritetile[i][j].getTexture() == &l.texture6) {
						k.kingsprite.move(-k.xVelocity, 0);
					}
				}

				if (l.spritetile[i][j].getGlobalBounds().intersects(interact.box.getGlobalBounds()) == true) {
					if (l.spritetile[i][j].getTexture() == &l.texture1 || l.spritetile[i][j].getTexture() == &l.texture3 || l.spritetile[i][j].getTexture() == &l.texture4 || l.spritetile[i][j].getTexture() == &l.texture5 || l.spritetile[i][j].getTexture() == &l.texture6) {
						interact.box.move(0, -interact.y);
					}
				}

				if (l.spritetile[i][j].getGlobalBounds().intersects(interact.box.getGlobalBounds()) == true) {
					if (l.spritetile[i][j].getTexture() == &l.texture1 || l.spritetile[i][j].getTexture() == &l.texture3 || l.spritetile[i][j].getTexture() == &l.texture4 || l.spritetile[i][j].getTexture() == &l.texture5 || l.spritetile[i][j].getTexture() == &l.texture6) {
						interact.box.move(-interact.x, 0);
					}
				}

				if (l.spritetile[i][j].getGlobalBounds().intersects(k.kingsprite.getGlobalBounds()) == true) {
					if (l.spritetile[i][j].getTexture() == &l.texture10) {
						interact.dead = true;
					}
				}

			}
		}


	d.doorclollision(k,interact);
	interact.coincollision(k);
	interact.bombcollision(k);



		window.clear();
		for (int x = 0; x < 13; x++) {
			for (int y = 0; y < 13; y++) {
				window.draw(l.spritetile[x][y]);
			}
		} 

		window.draw(d.door);

		if (interact.deletecoin == false) {
			window.draw(interact.coin);
		}
		window.draw(interact.box);
		//window.draw(interact.bomb);
		window.draw(k.kingsprite);
		window.display();
	}
	return 0;
}




