#pragma once
#include "List.h"
class Player
{
public:
	
		int health;
		int posX;
		int posY;
		char icon;

	
public:
	Player();
	Player(int _health, int _posX, int _posY, char _icon);
	~Player();
	void Move(char _dir); 

};

