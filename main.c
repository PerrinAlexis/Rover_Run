#include <stdio.h>
#include "map.h"
#include"tirage.h"
#include <time.h>
#include "loc.h"
#include"moves.h"

int main() {

    // demare le timer
    clock_t start_time = clock();
    clock_t build_time = clock(); // début de la fonction
    clock_t search_time = clock(); // a mettre avant l'algo de recherche
    clock_t path_time = clock(); // a mettre avant le chemin
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
    printf("Robot initialisé à la position :\n");
    printf("x : %d, y : %d, orientation : %s\n",
           robot.pos.x,
           robot.pos.y,
           (robot.ori == NORTH) ? "NORTH" :
           (robot.ori == EAST) ? "EAST" :
           (robot.ori == SOUTH) ? "SOUTH" : "WEST");

    // Tirage des moouvements
    t_move random_moves[9];
    printf("Random moves list:\n");
    for (int i = 0; i < 9; i++) {
        random_moves[i] = getRandomMove();
        printf("%s\n", getMoveAsString(random_moves[i]));
    }
    printf("Temps construction : %lf\n", (double)(build_time - start_time) / CLOCKS_PER_SEC);
    printf("Temps recherche : %lf\n", (double)(search_time - build_time) / CLOCKS_PER_SEC);
    printf("Temps calcul chemin : %lf\n", (double)(path_time - search_time) / CLOCKS_PER_SEC);



    return 0;
}
