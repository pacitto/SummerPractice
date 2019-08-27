#include "GameManager.h"



GameManager::GameManager()
{
	enemyList = List(6); 
	player = Player(50, 5, 5, '@'); 
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			Map[i][j] = '.';
		}
	}
	win = false; 

	for (int i = 0; i < enemyList.lenght; i++) 
	{
		Map[enemyList[i].posX][enemyList[i].posY] = enemyList[i].icon;
	}
	Map[player.posX][player.posY] = player.icon; 
	
}


GameManager::~GameManager()
{
}

void GameManager::checkInput()
{
	int lastPosX = player.posX;
	int lastPosY = player.posY; 
	
	char input = std::cin.get();
	player.Move(input); 
	if (player.posX != lastPosX || player.posY != lastPosY)
	{
		Map[lastPosX][lastPosY] = '.';
		Map[player.posX][player.posY] = player.icon;
	}
	}

	

void GameManager::CheckEnemies()
{
	for (int i = 0; i < enemyList.lenght; i++) {
		if (player.posX == enemyList[i].posX && player.posY == enemyList[i].posY)
		{
			player.health -= enemyList[i].health;
			enemyList.Erase(enemyList.GetNode(i)); 
		}
	}
}

void GameManager::Draw()
{
	std::cout << std::endl << std::endl<< std::endl<< std::endl << std::endl << std::endl << std::endl << std::endl << std::endl ;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			std::cout << " " << Map[i][j];
		}
		std::cout << std::endl;
	}
}

void GameManager::GameLoop()
{
	while (!win) {
		checkInput();
		CheckEnemies();
		Draw();
		CheckWin();
	}
}

void GameManager::CheckWin()
{
	if (enemyList.lenght == 0)
	{
		win = true; 
	}
}

