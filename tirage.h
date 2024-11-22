//
// Created by Alexis Perrin on 22/11/2024.
//

#ifndef UNTITLED1_TIRAGE_H
#define UNTITLED1_TIRAGE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tirage.h"
#define MV_10
#define MV_20
#define MV_30
#define RECUL_10
#define QUART_G
#define QUART_D
#define DEMI_T



typedef struct mvmt {
    int proba;
    char name[50];
} tab_mvmt_t;

tab_mvmt_t* create_tab();
void display_tab_mv();

#endif //UNTITLED1_TIRAGE_H
