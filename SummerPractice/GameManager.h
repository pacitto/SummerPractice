#pragma once
#include "List.h"
#include "Player.h"
class GameManager
{
	List enemyList; 
	Player player; 
	char Map[10][10]; 
	bool win; 

public:
	GameManager();
	~GameManager();

	void checkInput(); 
	void CheckEnemies();
	void Draw();
	void GameLoop(); 
	void CheckWin(); 
};

