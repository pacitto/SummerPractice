#include "Player.h"



Player::Player()
{

}

Player::Player(int _health, int _posX, int _posY, char _icon) {
	health = _health;
	posX = _posX;
	posY = _posY;
	icon = _icon;
}

Player::~Player()
{
}

void Player::Move(char _dir)
{
	if (_dir == 'w')
	{
		if (posY != 0) {
			posY--;
		}
	}
	if (_dir == 's')
	{
		if (posY != 9) {
			posY++;
		}
	}
	if (_dir == 'd')
	{
		if (posX != 9) {
			posX++;
		}
	}
	if (_dir == 'a')
	{
		if (posX != 0) {
			posX--;
		}
	}
}

