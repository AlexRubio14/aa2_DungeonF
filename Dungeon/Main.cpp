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
	
	int enemiesAlive = 5, chestClosed = NUM_COFRES; //Aquesta variable ens indicarà quants enemics queden vius
	Enemy goblin[5]; //Crearem 5 enemics (el random de 5 i 7 enemics ens ha petat el cap)
	for (int i = 0; i < 5; i++)
		goblin[i].Init();
	
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
			PrintStart(); 
			currentScene = NAVIGATION;
			break;
		case NAVIGATION:
			if (enemiesAlive == 0 && chestClosed == 0)
				currentScene = GAMEOVER;
			PrintMap (link, goblin, cofre, enemiesAlive);
			cin >> action;
			MoveAction(action, link, goblin, cofre, enemiesAlive);
			
			//SI ES TROBA AMB UN COFRE
			ChestFounded(link, cofre, chestFounded);
			if (chestFounded)
				currentScene = LOOTING;

			//SI ES TROBA AMB UN ENEMIC
			EnemyFounded(link, goblin, goblinFounded);
			if (goblinFounded)
				currentScene = COMBAT;
			break;
		case COMBAT:
			PlayCombat(link, goblin[5]);
			goblinFounded = false;
			if (link.isAlive == true && goblin[5].isAlive == false)
			{
				currentScene = NAVIGATION;
				enemiesAlive--;
			}
			if (link.isAlive == false)
				currentScene = GAMEOVER;
			break;
		case LOOTING:
			OpenChest(link,cofre, chestClosed);
			chestFounded = false;
			currentScene = NAVIGATION;
			break;
		case GAMEOVER:
			PrintGameover(link);
			break;
		default:
			break;
		}
	}
	return 0;
}

