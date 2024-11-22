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
    tab_mvt[0].proba = 22;
    strcpy(tab_mvt[1].name, "MV_20");
    tab_mvt[1].proba = 15;
    strcpy(tab_mvt[2].name, "MV_30");
    tab_mvt[2].proba = 7;
    strcpy(tab_mvt[3].name, "RECUL_10");
    tab_mvt[3].proba = 7;
    strcpy(tab_mvt[4].name, "QUART_G");
    tab_mvt[4].proba = 21;
    strcpy(tab_mvt[5].name, "QUART_D");
    tab_mvt[5].proba = 21;
    strcpy(tab_mvt[6].name, "DEMI_T");
    tab_mvt[6].proba = 7;

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

