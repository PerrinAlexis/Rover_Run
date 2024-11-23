#include <stdio.h>
#include "map.h"
#include"tirage.h"
#include <time.h>

int main() {
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

    // Tirage des moouvements
    tab_mvmt_t *tab_mvm = create_tab();
    display_tab_mv(tab_mvm,7);

    srand(time(NULL));
    int num_draws = 4;
    char* tab_res = perform_draws(tab_mvm, 9, num_draws);
    // Réinitialisation des disponibilités
    reset_availabilities(tab_mvm, 7);
    // Affichage du tableau des 9 tirage
    display_tab_res(tab_res,num_draws);
    return 0;
}
