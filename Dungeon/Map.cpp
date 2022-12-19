#include "Header.h"

void PrintMap(Player& link, Enemy goblin[]) {
	
	for (int i = 0; i < 5; i++)
		goblin[i].Init();

	// TOP PART
	printf("------ DUNGEON ------\n\nE -> Enemy    P -> Player    C -> Chest\n\nHealth: %d / %d\nPotion: %d / %d\nMoves: %d / %d\n\n",
		link.health, link.maxHealth, link.potions, link.maxPotion, link.moves, link.maxMoves);

	for (int i = 0; i < 5; i++)
		printf(" ___ ");

	printf("\n");

	//PRINT ROWS
	for (int i = 0; i < 5; i++)
	{
		//TOP PART
		for (int j = 0; j < 5; j++)
			printf("|   |");

		printf("\n");
		//MIDDLE PART
		for (int j = 0; j < 5; j++)
		{
			bool enemyFound = false, chestFound = false;

			//DECLARAR POSITION ENEMYS
			for (int k = 0; k < RandomNumber(5, 7); k++)
			{
				for (int k = 0; k < RandomNumber(5, 7); k++)
				{
					if (goblin[k].position.x == link.position.x && goblin[k].position.y == link.position.y)
					{
						goblin[k].position.x = RandomNumber(0, 4);
						goblin[k].position.y = RandomNumber(0, 4);
					}
					for (int o = 1; o < RandomNumber(5, 7); o++)
					{
						if (goblin[k].position.x == goblin[k - o].position.x && goblin[k].position.y == goblin[k - o].position.y)
						{
							goblin[k].position.x = RandomNumber(0, 4);
							goblin[k].position.y = RandomNumber(0, 4);
						}
					}
				}
				if (goblin[k].position.x == j && goblin[k].position.y == i)
					enemyFound = true;
			}

			if (link.position.x == j && link.position.y == i)
				printf("| P |");
			else if (enemyFound)
				printf("| E |");
			else if (chestFound)
				printf("| C |");
			else
				printf("|   |");
		}
		printf("\n");
		//BOTTOM PART
		for (int j = 0; j < 5; j++)
			printf("|___|");

		printf("\n");
	}
	printf("___________________\n\nW A S D -> Move\nP -> Potion\n\nEnter your action:");
	//system("pause");
}
/*
agility 
currentAgility
maxAgility 
*/
void MoveAction(char action, Player& link, Enemy goblin[]) 
{
	int i = link.position.x;
	int j = link.position.y;
	if (link.currentMoves == 0)
	{

	}
	while (link.moves > 0)
	{
		switch (action)
		{
		case 'W':
		case 'w':
			if (link.position.y == -1)
			{
				cout << "You can do this movement";
				break;
			}
			link.position.y = j - 1;
			link.moves--;
			break;
		case 'A':
		case 'a':
			if (link.position.x == -1)
			{
				cout << "You can't do this movement";
				break;
			}
			link.position.x = i - 1;
			link.moves--;
			break;
		case 'D':
		case 'd':
			if (link.position.x == 5)
			{
				cout << "You can't do this movement";
				break;
			}
			link.position.x = i + 1;
			link.moves--;
			break;
		case 'S':
		case 's':
			if (link.position.y == 5)
			{
				cout << "You can't do this movement";
				break;
			}
			link.position.y = j + 1;
			link.moves--;
			break;
		case 'P':
		case 'p':
			break;
		default: 
			cout << "ERROR";
			break;
		}
	}
	if (link.moves == 0)
		link.moves = link.maxMoves;

	//for comparant que no caigui amb cap enemic
	//currentScene = COMBAT

		
}//Fill the map with 10 bombs 
