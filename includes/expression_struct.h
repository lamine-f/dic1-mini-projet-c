// expression_struct.h
#ifndef EXPRESSION_STRUCT_H_INCLUDED
#define EXPRESSION_STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Expression_stack
typedef struct Expression_stack {
    char operator; // Opérateur de l'expression
    int value; // Valeur de l'expression
    struct Expression_stack *next_expression; // Pointeur vers l'expression suivante dans la pile
} Expression_stack;

// Prototypes des fonctions
int evaluate_expression (Expression_stack *exp); // Évalue une expression
Expression_stack *create_expression_stack(); // Crée une nouvelle pile d'expressions
int is_empty_expression_stack (Expression_stack *exp); // Vérifie si la pile d'expressions est vide
Expression_stack *clear_expression_stack (Expression_stack *exp); // Vide la pile d'expressions
Expression_stack *add_expression(Expression_stack *exp, char operator,  int value); // Ajoute une expression à la pile
void print_expression_stack(Expression_stack *exp); // Affiche la pile d'expressions

#endif
