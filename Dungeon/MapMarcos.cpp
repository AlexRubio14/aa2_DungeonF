#include "Header.h"

void PrintMap(Player& link, Enemy goblin[]) {

	//for (int i = 0; i < RandomNumber(4, 7); i++)
	//    goblin[i].Init();

	// TOP PART
	printf("------ DUNGEON ------\n\n E -> Enemy    P -> Player    C -> Chest\n\n Health: %d / %d\nPotion: %d / %d\nMoves: %d / %d\n\n", link.health, link.maxHealth, link.potions, link.maxPotion,
		link.agility, link.maxAgility);

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
			for (int k = 0; k < RandomNumber(5,7); k++)
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
	system("pause");

	//funtion marcos

}


void MoveAction(char action, Player& link, Enemy goblin[]) {

	//tot aixó en un while 
		if (link.currentAgility == 0)
		{

		}
		switch (action)
		{
		case 'W':
		case 'w':
			// link.position = link.position.y[i - 1];
			//tenir en compte que es pot sortir del mapa
			//Link agility--

			break;
		case 'A':
		case 'a':
		
		
			break;
		case 'D':
		case 'd':
		
		
			break;
		case 'S':
		case 's':
		
		
			break;
		default: 
			break;
		}
	//for comparant que no caigui amb cap enemic
	//currentScene = COMBAT


}