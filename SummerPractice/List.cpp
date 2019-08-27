#include "List.h"


List::List()								 //Constructor de una lista vacia
{
	first = nullptr;			
	last = nullptr;
	lenght = 0; 
}

List::List(int size)						 //Contructor de una lista dado su size crea x enemigos con valores de vida y posicion random
{
	lenght = 0; 
	for (int i = 0; i < size; i++)
	{
		int randomHealth = (rand() % 4) + 2; 
		int randomPosX = (rand() % 10);
		int randomPosY = (rand() % 10);
		char randomIcon = (i + 48);

		Enemy randomEnemy(randomHealth, randomPosX, randomPosY, randomIcon);
		Add(randomEnemy); 
	}
}

List::List(Enemy enemy)						//Constructor de una lista de enemies al que se le pasa un primer enemy
{
	first = new Node;						//El puntero first apunta a un nuevo nodo
	first->enemy = enemy;					//En este nuevo nodo se introduce la informacion del enemy
	first->next = nullptr;					//Se hace que los punteros a next y previous sean nulos (solos hay un nodo en la lista)
	first->previous = nullptr;
	
	last = first;							//El puntero last tambien apuntara a este nuevo modo (first)
	lenght = 1; 
}

List::List(List& list)						//Constructor por copia dandole una lista
{
	lenght = 0; 
	for (int i = 0; i < list.lenght; i++)
	{
		
		Add(GetNode(i)->enemy); 
	}
}


List::~List()
{
}

void List::Add(Enemy enemy)					//Funcion para añadir un nuevo enemigo a la lista
{

	if (lenght > 0) {						// si ya hay enemies en la lista

		last->next = new Node;				//se crea un nuevo nodo apuntado por el puntero next del last nodo(enemy) de la lista
		Node* previousLast = last;			//Un nuevo puntero apunta al last actual (antes de añadir el nuevo enemy)


		last = last->next;					//El puntero last pasa a apuntar al nuevo nodo introducido
		last->previous = previousLast;		//haremos que el puntero previous del nuevo last apunte al last anterior
		last->enemy = enemy;				//Introducimos la informacion de enemy en el nuevo nodo	
		last->next = nullptr;				//El next de nuestro last apunta a null
		lenght++;							//Incrementamos lenght
	}
	else {									//Si no hya ningún enemy en la lista
		first = new Node;					
		first->previous = nullptr;
		first->next = nullptr;
		first->enemy = enemy; 
		last = first; 
		lenght++; 
	}
}

void List::Erase(Node* pointer)             //Borra un nodo de enemy
{
	Node* newNext = pointer->next;          //Un nuevo puntero apunta al next del puntero
	Node* newPrevious = pointer->previous;	//Un nuevo puntero apunta al previous del puntero

	delete(pointer);						//Borramos la informacion del nodo apuntado por el puntero dado
	pointer = nullptr;						//Borramos el puntero al nodo dado	

	newNext->previous = newPrevious;		//El previous del nuevo next apunta al nuevo previous
	newPrevious->next = newNext;			//el next del nuevo previous apunta al nuevo next

}

void List::Insert(Node* newNode, int pos)	//Se inserta un nuevo nodo en la posicion dada
{
	Node* newPrevious = GetNode(pos - 1); 
	newPrevious->next = newNode; 
	
	Node* newNext = GetNode(pos + 1);
	newNext->previous = newNode; 

	newNode->next = newNext;
	newNode->previous = newPrevious; 


}

Node* List::GetNode(int pos)				//Nos retorna el nodo de la posicion dada
{
	Node* wantedNode = first;				//Se iguala el nodo buscado al first de la lista
	for (int i = 0; i < pos; i++)
	{
		wantedNode = wantedNode->next;		//Se iguala el nodo buscado al next de la lista hasta llegar a la posicion deseada
	}
	return wantedNode;
}

void List::eraseDefeated()					//Borra los nodos de los enemigos con vida menos o igual a 0
{
	for (int i = 0; i < lenght; i++)		//
	{
		Node* aux = GetNode(i); 
		if (aux->enemy.health <= 0)
		{
			Erase(aux);
		}
	}
}

Enemy List::operator[](int pos)
{
	Node* wantedNode = first;
	for (int i = 0; i < pos; i++)
	{
		wantedNode = wantedNode->next;
	}
	return wantedNode->enemy;
}

void List::printList()
{
	for (int i = 0; i < lenght; i++)
	{
		Node* enemy = GetNode(i); 
		std::cout << "The Enemy number " << i << " health " << enemy->enemy.health << " Pos x is " << enemy->enemy.posX << " Pos y is " << enemy->enemy.posY << " Icon is: " << enemy->enemy.icon <<  std::endl ; 
	}
}

