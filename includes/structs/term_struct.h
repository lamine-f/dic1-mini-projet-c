// term_struct.h
#ifndef TERM_STRUCT_H_INCLUDED
#define TERM_STRUCT_H_INCLUDED
#include <stdlib.h>

// Définition de la structure Term_stack
typedef struct Term_stack {
    int value; // Valeur du terme
    struct Term_stack *next_term; // Pointeur vers le terme suivant dans la pile
    char operator; // Opérateur du terme
} Term_stack ;

// Prototypes des fonctions
int evaluate_term (Term_stack *term_stack); // Évalue un terme
Term_stack *create_term_stack(); // Crée une nouvelle pile de termes
int is_empty_term_stack (Term_stack *term_stack); // Vérifie si la pile de termes est vide
Term_stack *clear_term_stack (Term_stack *term_stack); // Vide la pile de termes
Term_stack *add_term(Term_stack *term_stack, char operator, int value); // Ajoute un terme à la pile

#endif
