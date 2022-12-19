#include "Header.h"

enum Scene { START, NAVIGATION, COMBAT, LOOTING, GAMEOVER };


int main()
{
	
	srand(time(NULL));

	Scene currentScene = NAVIGATION;

	char action;

	Player link;
	link.Init();

	Enemy goblin[5];
	Chest cofre[2];
	for (int i = 0; i < 2; i++)
		cofre[i].Init();
	CrearCofres(link, cofre);
	
	
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
			
			PrintMap (link, goblin, cofre);
			cin >> action;
			MoveAction(action, link, goblin, cofre);
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
			system("cls");
			cout << "Estas en looting";
			system("pause");
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

void ChestFounded(Player& link, Chest cofre[]) {
	for (int i = 0; i < 2; i++)
	{
		if (link.position.x == cofre[i].position.x && link.position.x == cofre[i].position.y)
		{
			cofre[i].position.x = 30;
			//link.moves
			Scene currentScene = LOOTING;
		}
	}
}