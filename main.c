#include <stdio.h>
#include "map.h"
#include"tirage.h"
#include <time.h>
#include"moves.h"
#include "tree.h"


int main() {

    // demare le timer
    clock_t start_time = clock();
    clock_t build_time = clock(); // début de la fonction ca tu touche pas
    clock_t search_time = clock(); // a mettre avant l'algo de recherche, création de l'arbre avant de créer l'arbre dans le main
    clock_t path_time = clock(); // a mettre avant le chemin avant de choisir le meilleur chemin pour notre robot
    t_map map;
    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
    calculateCosts(map);

    // Initialise la position du robot
    t_localisation robot = loc_init(5, 6, NORTH);
    // Affichage de la localisation initiale du robot
    printf("Robot initialise a la position :\n");
    printf("x : %d, y : %d, orientation : %s\n",
           robot.pos.x,
           robot.pos.y,
           (robot.ori == NORTH) ? "NORTH" :
           (robot.ori == EAST) ? "EAST" :
           (robot.ori == SOUTH) ? "SOUTH" : "WEST");

    // Tirage des moouvements
    tab_mvmt_t *tab_mvm = create_tab();
    display_tab_mv(tab_mvm,7);

    srand(time(NULL));
    int num_draws = 9;
    perform_draws(tab_mvm, 7, num_draws);
    // Reinitialisation des disponibilites
    reset_availabilities(tab_mvm, 7);

    // Tirage des moouvements
    t_move random_moves[9];
    printf("Random moves list:\n");
    for (int i = 0; i < 9; i++) {
        random_moves[i] = getRandomMove();
        printf("%s\n", getMoveAsString(random_moves[i]));
    }


    // Creation des localisations pour les mouvements aleatoires
    t_localisation locs[9];
    for (int i = 0; i < 9; i++) {
        locs[i] = loc_init(robot.pos.x, robot.pos.y, robot.ori);
        updateLocalisation(&locs[i], random_moves[i]);
    }


    // Creation de l'arbre
    printf("\nCreation de l'arbre...\n");
    Node* root = createNode(0, F_10, robot, NULL);

    clock_t start_1 = clock();
    createTree(root, random_moves, locs, 9, 5,&map);
    clock_t end_1 = clock();


    // Affichage de l'arbre
    //printf("\nStructure de l'arbre genere :\n");
    //displayTreeStructure(root, 0, 5);

    // Recherche de la feuille avec le cout minimal
    printf("\n\nRecherche de la feuille avec le cout minimal...\n");
    clock_t start_2 = clock();
    path_to_min_leaf(root);
    clock_t end_2 = clock();

    // Liberation des ressources (si necessaire)
    // freeTree(root);

    //temps d'execution
    printf("Le temps de construction de l'arbre est de : %f seconde(s)\n", (double)(end_1 - start_1) / CLOCKS_PER_SEC);
    printf("Le temps de calcul du chemin : %f secondes\n", (double)(end_2 - start_2) / CLOCKS_PER_SEC);
    return 0;
}
