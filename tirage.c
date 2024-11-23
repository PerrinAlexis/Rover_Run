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

    // Remplissage des valeurs
    strcpy(tab_mvt[0].name, "MV_10");
    tab_mvt[0].proba = MV_10;
    tab_mvt[0].availability = MV_10;

    strcpy(tab_mvt[1].name, "MV_20");
    tab_mvt[1].proba = MV_20;
    tab_mvt[1].availability = MV_20;

    strcpy(tab_mvt[2].name, "MV_30");
    tab_mvt[2].proba = MV_30;
    tab_mvt[2].availability = MV_30;

    strcpy(tab_mvt[3].name, "RECUL_10");
    tab_mvt[3].proba = RECUL_10;
    tab_mvt[3].availability = RECUL_10;

    strcpy(tab_mvt[4].name, "QUART_G");
    tab_mvt[4].proba = QUART_G;
    tab_mvt[4].availability = QUART_G;

    strcpy(tab_mvt[5].name, "QUART_D");
    tab_mvt[5].proba = QUART_D;
    tab_mvt[5].availability = QUART_D;

    strcpy(tab_mvt[6].name, "DEMI_T");
    tab_mvt[6].proba = DEMI_T;
    tab_mvt[6].availability = DEMI_T;

    return tab_mvt;
}

//afficher le tableau
void display_tab_mv(tab_mvmt_t *tab, int size) {
    if (tab == NULL || size <= 0) {
        printf("Le tableau est vide ou invalide.\n");
        return;
    }

    printf("Contenu du tableau de mouvements :\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Mouvement %d:\n", i + 1);
        printf("  - Probabilité : %d\n", tab[i].proba);
        printf("  - Nom         : %s\n", tab[i].name);
    }
    printf("-----------------------------------\n");
}

int draw_movement(tab_mvmt_t *tab, int size) {
    int total_weight = 0;

    // Calculer la somme des disponibilités
    for (int i = 0; i < size; i++) {
        total_weight += tab[i].availability;
    }

    if (total_weight == 0) {
        printf("Erreur : aucune disponibilité restante.\n");
        return -1;
    }

    // Générer un nombre aléatoire entre 0 et total_weight - 1
    int random_value = rand() % total_weight;

    // Identifier le mouvement correspondant
    int cumulative_weight = 0;
    for (int i = 0; i < size; i++) {
        cumulative_weight += tab[i].availability;
        if (random_value < cumulative_weight) {
            // Réduire la disponibilité du mouvement sélectionné
            tab[i].availability--;
            return i;
        }
    }

    return -1; // Cas théorique, ne devrait jamais arriver
}

void perform_draws(tab_mvmt_t *tab, int size, int num_draws) {
    printf("Début des tirages de mouvements :\n");
    for (int i = 0; i < num_draws; i++) {
        int movement_index = draw_movement(tab, size);
        if (movement_index != -1) {
            printf("Tirage %d : %s\n", i + 1, tab[movement_index].name);
        } else {
            printf("Impossible de tirer un mouvement. Toutes les disponibilités sont à 0.\n");
            break;
        }
    }
    printf("Fin des tirages.\n");
}

void reset_availabilities(tab_mvmt_t *tab, int size) {
    for (int i = 0; i < size; i++) {
        tab[i].availability = tab[i].proba;
    }
    printf("Disponibilités réinitialisées.\n");
}
