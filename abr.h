// permet de représenter et manipuler une séquence de mouvements en partant d'une position initiale
#include "loc.h"
#include "moves.h"

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

// Structure d'un nœud de l'arbre, représentant une action donnée
typedef struct s_node
{
    struct s_node **children;   // Pointeur vers les enfants de ce nœud
    struct s_node *parent;      // Pointeur vers le parent de ce nœud
    t_position localisation;    // Position associée au nœud
    t_move movement;            // Mouvement associé à ce nœud
    int cost;                   // Coût associé à ce nœud
    int num_children;           // Nombre d'enfants de ce nœud
} t_node;

// Structure de la racine de l'arbre, représentant le point de départ sans mouvement associé
typedef struct s_root
{
    int cost;                   // Coût initial (pour la racine)
    t_node **children;          // Pointeur vers les enfants de la racine
    int num_children;           // Nombre d'enfants de la racine
} t_root;

// Structure de l'arbre complet
typedef struct s_tree
{
    t_root *root;               // Pointeur vers la racine de l'arbre
} t_tree;

// Prototypes pour les fonctions de gestion de l'arbre

// Crée un nœud en lui assignant une position, un mouvement et un coût
t_node* create_node(t_position pos, t_move mov, int cost);

// Libère la mémoire allouée pour un nœud et tous ses enfants
void free_node(t_node* node);

// Ajoute un nœud enfant à un nœud parent donné
void add_child(t_node* parent, t_node* child);

#endif // UNTITLED1_TREE_H
