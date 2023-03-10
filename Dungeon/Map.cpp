#include "Header.h"

void PrintMap(Player& link, Enemy goblin[], Chest cofre[], int& menosEnemy) {
	
	if (link.moves == 0)
	{
		//Inicialitzar els enemics cada vegada que s'han de moure 
		//(sabem que no es molt optim pero no sabiem fer-ho d'un altre manera)
		for (int i = 0; i < 5; i++)
		{
			if (i < menosEnemy)
				goblin[i].Init();
			else
			{
				goblin[i].Init();
				goblin[i].position.x = 30 + i;
			}
		}
		link.moves = link.maxMoves;
	}

	// TOP PART
	printf("------ RADEV'S CASTLE ------\n\nE -> Enemy    P -> Player    C -> Chest\n\nHealth: %d / %d\nPotions: %d / %d\nMoves: %d / %d\n\n",
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

			//Comprovar que no es superposen els CHESTS amb altres elements //DECLARAR CHEST AL MAPA
			for (int c = 0; c < 2; c++)	{
				for (int k = 0; k < menosEnemy; k++)
				{
					if (cofre[k].position.x == link.position.x && cofre[k].position.y == link.position.y)
					{
						cofre[k].position.x = RandomNumber(0, 4);
						cofre[k].position.y = RandomNumber(0, 4);
					}
				}
				if (cofre[c].position.x == j && cofre[c].position.y == i)
					chestFound = true;
			}
			
			//Comprovar que no es superposen els ENEMIES amb altres elements //DECLARAR ENEMIES AL MAPA
			if (link.moves == link.maxMoves) {		
				for (int k = 0; k < menosEnemy; k++)
				{
					for (int k = 0; k < menosEnemy; k++)
					{
						if (goblin[k].position.x == link.position.x && goblin[k].position.y == link.position.y || goblin[k].position.x == cofre[0].position.x &&
							goblin[k].position.y == cofre[0].position.y || goblin[k].position.x == cofre[1].position.x &&
							goblin[k].position.y == cofre[1].position.y)
						{
							goblin[k].position.x = RandomNumber(0, 4);
							goblin[k].position.y = RandomNumber(0, 4);
						}
						for (int z = 1; z < 5; z++)
						{
							if (goblin[k].position.x == goblin[k - z].position.x && goblin[k].position.y == goblin[k - z].position.y)
							{
								goblin[k].position.x = RandomNumber(0, 4);
								goblin[k].position.y = RandomNumber(0, 4);
							}
						}
					}
					if (goblin[k].position.x == j && goblin[k].position.y == i)
						enemyFound = true;
				}
			}
			else {
				for (int k = 0; k < 5; k++)
				{
					for (int k = 0; k < 5; k++)
					{
			
							goblin[k].position.x = goblin[k].position.x;
							goblin[k].position.y = goblin[k].position.y;
					}
					if (goblin[k].position.x == j && goblin[k].position.y == i)
						enemyFound = true;
				}
			}

			//PRINT CHARACTERS IN MAP
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
}

void MoveAction(char action, Player& link, Enemy goblin[], Chest cofre[], int& menosEnemy)
{
	int i = link.position.x, j = link.position.y;

	switch (action)
	{
		case 'W':
		case 'w':
			if (link.position.y == 0)
			{
				cout << "You can't do this movement! " << endl;

				system("cls");
				break;
			}
			link.position.y = j - 1;
			link.moves--;
;
			system("cls");
			break;
		case 'A':
		case 'a':
			if (link.position.x == 0)
			{
				cout << "You can't do this movement! " << endl;

				system("cls");
				break;
			}
			link.position.x = i - 1;
			link.moves--;

			system("cls");
			break;
		case 'D':
		case 'd':
			if (link.position.x == 4)
			{
				cout << "You can't do this movement! " << endl;

				system("cls");
				break;
			}
			link.position.x = i + 1;
			link.moves--;
			system("cls");
			break;
		case 'S':
		case 's':
			if (link.position.y == 4)
			{
				cout << "You can't do this movement! " << endl;
	
				system("cls");
				break;
			}
			link.position.y = j + 1;
			link.moves--;

			system("cls");
			break;
		case 'P':
		case 'p':
			DrinkPotion(link);
			link.moves--;
			system("pause");
			system("cls");
			break;
		default: 
			cout << "ERROR" << endl;

			system("cls");
			break;
	}
}