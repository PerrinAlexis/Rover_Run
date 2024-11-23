//
// Created by Alexis Perrin on 22/11/2024.
//

#ifndef UNTITLED1_TIRAGE_H
#define UNTITLED1_TIRAGE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tirage.h"
#define MV_10 22
#define MV_20 15
#define MV_30 7
#define RECUL_10 7
#define QUART_G 21
#define QUART_D 21
#define DEMI_T 7
#define P_TOT 100


typedef struct mvmt {
    int proba;         // Probabilité de base du mouvement
    int availability;  // Disponibilité restante pour le tirage
    char name[50];     // Nom du mouvement
} tab_mvmt_t;

tab_mvmt_t* create_tab();
void display_tab_mv();
int draw_movement();
char **perform_draws();
void reset_availabilities();
void display_tab_res();

#endif //UNTITLED1_TIRAGE_H
