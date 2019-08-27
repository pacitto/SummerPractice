#include "List.h"
#include <iostream>
#include "GameManager.h"

struct Character {
	int health;
	int posX;
	int posY;
	char icon; 

};

void main() {

	GameManager game;
	game.GameLoop();
	 


	system("pause"); 

}
