#pragma once
#include<iostream>
struct Enemy {						//struct de enemies
		int health;
		int posX;
		int posY;
		char icon; 
		Enemy() {

		}
		Enemy(int _health, int _posX, int _posY, char _icon){     //constructor de enemy
			health = _health;
			posX = _posX;
			posY = _posY; 
			icon = _icon; 
		}
	};

struct Node {				//stuct de nodos formados por 
		Enemy enemy;		//Un tipo enemigo
		Node* next;			// Y dos punteros, uno apuntando al nodo anterior y el otro al siguiente
		Node* previous;
	};

class List					//Clase List con nodos que apuntaran al primero y al ultimo de los nodos que formaran la lista
{
	Node* first; 
	Node* last; 
	
public:
	int lenght;
	List();
	List(int size); 
	List(Enemy enemy); 
	List(List &list); 
	~List();
	void Add(Enemy enemy);
	void Erase(Node* pointer); 
	void Insert(Node* pointer, int pos); 
	Node* GetNode(int pos);
	void eraseDefeated(); 
	Enemy operator[](int pos); 
	void printList(); 
	
};

