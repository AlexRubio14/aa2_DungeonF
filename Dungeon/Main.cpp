#include "Header.h"

enum Scene { START, NAVIGATION, COMBAT, LOOTING, GAMEOVER };

int main()
{
	srand(time(NULL));

	Scene currentScene = NAVIGATION;
	bool isPlaying = true;

	Player link;
	link.Init();
	int totalGoblins = RandomNumber(5,7);
	Enemy goblin[5];
	CreateEnemies(link, goblin);
	//Chest cofre[2];

	char playerAction;

	while (isPlaying)
	{
		switch (currentScene)
		{
		case START:
		
			//afegir tota la introducció del joc
			//currentScene = NAVIGATION;
			//system("cls"); //netejar la consola
			break;
		case NAVIGATION:
			
			PrintMap (link, goblin);
			//introduir tot el mapa
			//el mapejat dels objectes, enemics...
			//moviment
			//if per entrar als diversos escenaris
			//currentScene = LOOTING; //agafa cofre
			//currentScene = COMBAT; //cau amb enemic
			//currentScene = NAVIGATION; //no cau en res
			break;
		case COMBAT:
			//afegir tot el combat
			//currentScene = NAVIGATION; //torna al mapa amb 1 enemic menys al mapa
			break;
		case LOOTING:
			//afegir tot el sistema de cofres
			break;
		case GAMEOVER:
			//missatge de gameover
			//isPlaying = false;
			break;
		default:
			//ns que va aquí pero estava posat en els apunts
			break;
		}
	}
}

int RandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void CreateEnemies(Player& link, Enemy goblin[]) {

	//DECLARAR QUE HI HA 5 ENEMICS
	for (int k = 0; k < 5; k++)
	{

		//si el enemigo encaja con el player se recoloca su posicion
		if (goblin[k].position.x == link.position.x && goblin[k].position.y == link.position.y)
		{
			goblin[k].position.x = RandomNumber(0, 4);
			goblin[k].position.y = RandomNumber(0, 4);
		}
	}
}