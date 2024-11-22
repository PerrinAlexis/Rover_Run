// permet de représenter et manipuler une séquence de mouvements en partant d'une position initiale
#include "loc.h"
#include "moves.h"
#include "abr.h"

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

// Structure d'un nœud de l'arbre, représentant une action donnée
typedef struct s_node
{
    struct s_node ** children;    
    struct s_node * parent;       
    t_position localisation;    
    t_move movement;             
    int cost;                    
    int num_children;            
} t_node;

// Structure de la racine de l'arbre, représentant -> le point de départ sans mouvement associé
typedef struct s_root
{
    int cost;                    
    struct s_node ** children;   
// Structure de l'arbre complet
typedef struct s_tree
{
    t_root* tree;   
} t_tree;

// Prototypes pour les fonctions de gestion de l'arbre

// Crée un nœud en lui assignant une position, un mouvement et un coût
t_node* create_node(t_position pos, t_move mov, int cost);

// Libère la mémoire allouée pour un nœud et tous ses enfants
void free_node(t_node* node);

// Ajoute un nœud enfant à un nœud parent donné
void add_child(t_node* parent, t_node* child);

#endif // UNTITLED1_TREE_H
