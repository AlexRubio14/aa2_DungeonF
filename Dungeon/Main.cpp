#include "Header.h"

enum Scene { START, NAVIGATION, COMBAT, LOOTING, GAMEOVER };

//Joc inspirat en "The Legend of Zelda" :)
int main()
{
	srand(time(NULL));

	Scene currentScene = START; //Dividim el joc en escenes i inicialitzem a Start
	
	char action;
	Player link; //Inicialitzem el jugador 
	link.Init();

	int enemiesAlive = 5; //Aquesta variable ens indicarà quants enemics queden vius
	Enemy goblin[5]; //Crearem 5 enemics (el random de 5 i 7 enemics ens ha petat el cap)
	
	Chest cofre[NUM_COFRES]; //Inicialitzem els cofres
	for (int i = 0; i < NUM_COFRES; i++)
		cofre[i].Init();
	CrearCofres(link, cofre);
	
	bool isPlaying = true, chestFounded = false, goblinFounded = false;

	while (isPlaying)
	{
		switch (currentScene)
		{
		case START:
			Start(); 
			currentScene = NAVIGATION;
			break;
		case NAVIGATION:
			PrintMap (link, goblin, cofre, enemiesAlive);
			cin >> action;
			MoveAction(action, link, goblin, cofre);
			ChestFounded(link, cofre, chestFounded);
			EnemyFounded(link, goblin, goblinFounded);
			if (chestFounded)
				currentScene = LOOTING;
			else if (goblinFounded)
			{
				currentScene = COMBAT;
				goblinFounded = false;
			}

			break;
		case COMBAT:
			system("cls");
			PlayCombat(link, goblin[5]);
			system("Pause");
			if (link.isAlive == true && goblin[5].isAlive == false)
			{
				currentScene = NAVIGATION;
				enemiesAlive--;
			}
			if (link.isAlive == false)
				currentScene = GAMEOVER;
			if (enemiesAlive == 0)
				currentScene = GAMEOVER;
			break;
		case LOOTING:
			system("cls");
			OpenChest(link,cofre);
			chestFounded = false;
			currentScene = NAVIGATION;
			system("pause");
			break;
		case GAMEOVER:
			PrintGameover(link, isPlaying);
			currentScene = START;
			break;
		default:
			//ns que va aquí pero estava posat en els apunts
			break;
		}
	}
 
	return 0;
}

int RandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

bool ChestFounded(Player& link, Chest cofre[], bool& chestFounded) {
	
	for (int i = 0; i < 2; i++)
	{
		if (link.position.x == cofre[i].position.x && link.position.y == cofre[i].position.y)
		{
			cofre[i].position.x = 30;
			//link.moves
			Scene currentScene = LOOTING;
			chestFounded = true;
		}
	}
	return chestFounded;
}

bool EnemyFounded(Player& link, Enemy goblin[], bool& goblinFounded) {

	for (int i = 0; i < 5; i++)
	{
		if (link.position.x == goblin[i].position.x && link.position.y == goblin[i].position.y)
		{
			goblin[i].position.x = 30;
			//link.moves
			Scene currentScene = COMBAT;
			goblinFounded = true;
		}
	}
	return goblinFounded;
}

