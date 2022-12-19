#include "Header.h"

enum Scene { START, NAVIGATION, COMBAT, LOOTING, GAMEOVER };

int main()
{
	char action;
	srand(time(NULL));

	Player link;
	link.Init();

	Enemy goblin[5];

	Scene currentScene = NAVIGATION;
	bool isPlaying = true;

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
			cin >> action;
			MoveAction(action, link, goblin);
			//introduir tot el mapa
			//el mapejat dels objectes, enemics...
			//moviment
			//if per entrar als diversos escenaris
			//currentScene = LOOTING; //agafa cofre
			//currentScene = COMBAT; //cau amb enemic
			//currentScene = NAVIGATION; //no cau en res
			break;
		case COMBAT:
			system("Pause");
			//PlayCombat( link, goblin);
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