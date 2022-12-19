////#include "Header.h"
//
//void PrintMap(Player& link, Enemy goblin[]) {
//   
//    int totalGoblins = RandomNumber(5, 7);
//    for (int i = 0; i < totalGoblins; i++)
//    {
//        goblin[i].Init();
//    }
//    // TOP PART
//    printf("------ DUNGEON ------\n\nE -> Enemy    P -> Player    C -> Chest\n\nHealth: %d / %d\nPotion: %d / %d\nMoves: %d / %d\n\n", 
//        link.health, link.maxHealth, link.potions, link.maxPotion, link.agility, link.maxAgility);
//
//    for (int i = 0; i < NUM_COLUMS; i++)
//    {
//        printf(" ___ ");
//    }
//    printf("\n");
//
//    //PRINT ROWS
//    for (int i = 0; i < NUM_ROWS; i++)
//    {
//     
//        //TOP PART
//        for (int j = 0; j < NUM_COLUMS; j++)
//        {
//            printf("|   |");
//        }
//        printf("\n");
//        //MIDDLE PART
//        for (int j = 0; j < NUM_COLUMS; j++)
//        {
//            bool enemyFound = false, chestFound = false;
//            for (int k = 0; k < 5; k++)
//            {
//                if (goblin[k].position.x == j && goblin[k].position.y == i)
//                    enemyFound = true;
//            }
//           
//            //DECLARAR QUE HI HA 2 COFRES // sense comprobar si funciona
//            /*for (int k = 0; k < 2; k++)
//            {
//                //si el cofre encaja con el player o l'enemy se recoloca su posicion             
//                if (c[k].position.x == link.position.x && c[k].position.y == link.position.y 
//                    || c[k].position.x == e[k].position.x && c[k].position.y == e[k].position.y)
//                {
//                    c[k].position.y = RandomNumber(0, 4);
//                    c[k].position.y = RandomNumber(0, 4);
//                }
//                if (c[k].position.x == j && c[k].position.y == i)
//                {
//                    chestFound = true;
//                }
//            }*/
//
//            if (link.position.x == j && link.position.y == i)
//                printf("| P |");
//            else if (enemyFound)
//                printf("| E |");
//            else if (chestFound)
//                printf("| C |");
//            else
//                printf("|   |");
//        }
//        printf("\n");
//        //BOTTOM PART
//        for (int j = 0; j < NUM_COLUMS; j++)
//        {
//            printf("|___|");
//        }
//        printf("\n");
//    }
//    printf("_________________________\n\nW A S D -> Move\nP -> Potion\n\nEnter your action: ");
//    system("pause");
//}
//
