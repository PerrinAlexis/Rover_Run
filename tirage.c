//
// Created by Alexis Perrin on 22/11/2024.
//

#include "tirage.h"
// créer le tableau

tab_mvmt_t* create_tab() {
    tab_mvmt_t *tab_mvt = (tab_mvmt_t*)malloc(7 * sizeof(tab_mvmt_t));
    if (tab_mvt == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    strcpy(tab_mvt[0].name, "MV_10");
    tab_mvt[0].proba = tab_mvt[0].availability = MV_10;

    strcpy(tab_mvt[1].name, "MV_20");
    tab_mvt[1].proba = tab_mvt[1].availability = MV_20;

    strcpy(tab_mvt[2].name, "MV_30");
    tab_mvt[2].proba = tab_mvt[2].availability = MV_30;

    strcpy(tab_mvt[3].name, "RECUL_10");
    tab_mvt[3].proba = tab_mvt[3].availability = RECUL_10;

    strcpy(tab_mvt[4].name, "QUART_G");
    tab_mvt[4].proba = tab_mvt[4].availability = QUART_G;

    strcpy(tab_mvt[5].name, "QUART_D");
    tab_mvt[5].proba = tab_mvt[5].availability = QUART_D;

    strcpy(tab_mvt[6].name, "DEMI_T");
    tab_mvt[6].proba = tab_mvt[6].availability = DEMI_T;

    return tab_mvt;
}

void display_tab_mv(tab_mvmt_t *tab, int size) {
    for (int i = 0; i < size; i++) {
        printf("Mouvement %d: %s (Probabilité : %d, Disponibilité : %d)\n",
               i + 1, tab[i].name, tab[i].proba, tab[i].availability);
    }
}

int draw_movement(tab_mvmt_t *tab, int size) {
    int total_weight = 0;
    for (int i = 0; i < size; i++) total_weight += tab[i].availability;

    if (total_weight == 0) return -1;

    int random_value = rand() % total_weight;
    int cumulative_weight = 0;
    for (int i = 0; i < size; i++) {
        cumulative_weight += tab[i].availability;
        if (random_value < cumulative_weight) {
            tab[i].availability--;
            return i;
        }
    }
    return -1;
}

char **perform_draws(tab_mvmt_t *tab, int size, int num_draws) {
    char **tab_res = malloc(num_draws * sizeof(char *));
    if (tab_res == NULL) return NULL;

    for (int i = 0; i < num_draws; i++) {
        int movement_index = draw_movement(tab, size);
        printf("Tirage %d : %s\n", i + 1, tab[movement_index].name);
        tab_res[i] = strdup(tab[movement_index].name);
    }
    return tab_res;
}

void reset_availabilities(tab_mvmt_t *tab, int size) {
    for (int i = 0; i < size; i++) {
        tab[i].availability = tab[i].proba;
    }
}

// print le tableau des choix

void display_tab_res(char **tab_res, int num_draws) {
    if (tab_res == NULL || num_draws <= 0) {
        printf("Le tableau des résultats est vide ou invalide.\n");
        return;
    }

    printf("Résultats des tirages :\n");
    printf("-----------------------\n");
    for (int i = 0; i < num_draws; i++) {
        if (tab_res[i] != NULL) {
            printf("%d. %s\n", i + 1, tab_res[i]);
        } else {
            printf("%d. (Vide)\n", i + 1);
        }
    }
    printf("-----------------------\n");
}