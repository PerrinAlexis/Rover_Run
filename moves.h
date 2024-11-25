#ifndef UNTITLED1_MOVES_H
#define UNTITLED1_MOVES_H

#include "loc.h" // Inclut déjà la définition de e_orientation et t_orientation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * @brief Array of strings for the possible moves of the robot
 */
static const char _moves[8][8] = {"F 10m", "F 20m", "F 30m", "B 10m", "T left", "T right", "U-turn"};

/**
 * @brief Enum for the possible moves of the robot
 */
typedef enum e_move {
    F_10,    // Forward 10 m
    F_20,    // Forward 20 m
    F_30,    // Forward 30 m
    B_10,    // Backward 10 m
    T_LEFT,  // Turn left (+90°)
    T_RIGHT, // Turn right (-90°)
    U_TURN   // U-turn (180°)
} t_move;

/**
 * @brief Function to get a t_move as a string
 * @param move : the move to convert
 * @return the string corresponding to the move
 */
char *getMoveAsString(t_move move);

/**
 * @brief Function to update the localisation of the robot according to a move
 * @param loc : the localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation move(t_localisation loc, t_move move);

/**
 * @brief Wrapper function to update a single location
 * @param p_loc : the pointer to the localisation of the robot
 * @param move : the move to do
 */
void updateLocalisation(t_localisation *p_loc, t_move move);

/**
 * @brief Function to get a random move based on weighted probabilities
 * @return A random t_move
 */
t_move getRandomMove();

/**
 * @brief Function to rotate the robot based on its current orientation and move
 * @param ori : the current orientation of the robot
 * @param move : the move to execute
 * @return The new orientation of the robot
 */
t_orientation rotate(t_orientation ori, t_move move);

/**
 * @brief Function to translate the robot based on its current localisation and move
 * @param loc : the current localisation of the robot
 * @param move : the move to execute
 * @return The new localisation of the robot
 */
t_localisation translate(t_localisation loc, t_move move);

#endif // UNTITLED1_MOVES_H
