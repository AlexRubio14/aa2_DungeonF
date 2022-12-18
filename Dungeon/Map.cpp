#include "Map.h"


//void PrintMap(Player link, Enemy e[]) {
//    // TOP PART
//        // TOP PART
//    printf("------ DUNGEON ------\n\n E -> Enemy    P -> Player    C -> Chest\n\nHealth: %d / %d\nPotion: %d / %d\nMoves: %d / %d\n\n", link.health, link.maxHealth, link.potions, 
//        link.maxPotion, link.agility, link.maxAgility);
//    for (int i = 0; i < 5; i++)
//    {
//        printf(" ___ ");
//    }
//    printf("\n");
//    //PRINT ROWS
//    for (int i = 0; i < 5; i++)
//    {
//        //TOP PART
//        for (int j = 0; j < 5; j++)
//        {
//            printf("|   |");
//        }
//        printf("\n");
//        //MIDDLE PART
//        for (int j = 0; j < 5; j++)
//        {
//            bool enemyFound = false;
//            bool chestFound = false;
//
//            for (int k = 0; k < RandomBetweenRange(5,7); k++)
//            {
//                if (e[k].position.x == link.position.x && e[k].position.y == link.position.y)
//                {
//                    e[k].position.x = RandomBetweenRange(0, 4);
//                    e[k].position.y = RandomBetweenRange(0, 4);
//                }
//
//                if (e[k].position.x == j && e[k].position.y == i)
//                {
//                    enemyFound = true;
//
//                }
//
//            }
//                /*
//            for (int k = 0; k < 2; k++)
//            {
//                if (c[k].position.x == link.position.x && c[k].position.y == link.position.y)
//                {
//                    c[k].position.x = RandomBetweenRange(0, 4);
//                    c[k].position.y = RandomBetweenRange(0, 4);
//                }
//                for (int t = 0; t < 5; t++) 
//                {
//                    if(c[k].position.x == e[t].position.x && c[k].position.y == e[t].position.y)
//                }
//
//                if (c[k].position.x == j && c[k].position.y == i)
//                {
//                    chestFound = true;
//
//                }
//
//            }
//                */
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
//        for (int j = 0; j < 5; j++)
//        {
//            printf("||");
//        }
//        printf("\n");
//
//
//    }
//    printf("___\n\nW A S D -> Move\nP -> Potion\n\nEnter your action:");
//}