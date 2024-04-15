// expression_struct.c
#include "../includes/expression_struct.h"

// Évalue une expression
int evaluate_expression (Expression_stack *exp_stack) {
    Expression_stack *current = exp_stack;
    int previous_value = 0;
    int value = current->value;
    while ( !is_empty_expression_stack(current) ) {
        int current_value = current->value;
        switch (current->operator) {
            case '+':
                value = current_value + previous_value; // Si l'opérateur est '+', ajoute la valeur précédente à la valeur courante
                break;
            case '-':
                value = current_value - previous_value; // Si l'opérateur est '-', soustrait la valeur précédente de la valeur courante
                break;
            default:
                break;
        }
        previous_value = value;
        current = current->next_expression;
    }
    return value; // Retourne la valeur finale de l'expression
}

// Vide la pile d'expressions
Expression_stack *clear_expression_stack (Expression_stack *exp_stack) {
    if (is_empty_expression_stack(exp_stack) )
        return NULL;
    Expression_stack *next_exp_stack = exp_stack->next_expression;
    free(exp_stack); // Libère la mémoire allouée à l'expression courante
    return clear_expression_stack(next_exp_stack); // Appelle récursivement la fonction pour le reste de la pile
}

// Crée une nouvelle pile d'expressions
Expression_stack *create_expression_stack () {
    return NULL; // Retourne NULL car la pile est initialement vide
}

// Vérifie si la pile d'expressions est vide
int is_empty_expression_stack (Expression_stack *exp_stack) {
    return (exp_stack == NULL); // Retourne vrai si la pile est vide, faux sinon
}

// Ajoute une expression à la pile
Expression_stack *add_expression(Expression_stack *exp_stack, char operator, int value) {
    Expression_stack *new_exp_stack = malloc(sizeof(*new_exp_stack)); // Alloue de la mémoire pour la nouvelle expression
    new_exp_stack->operator = operator; // Affecte l'opérateur à la nouvelle expression
    new_exp_stack->value = value; // Affecte la valeur à la nouvelle expression
    new_exp_stack->next_expression = exp_stack; // Fait pointer la nouvelle expression vers l'expression précédente
    return new_exp_stack; // Retourne la nouvelle pile d'expressions
}

// Affiche la pile d'expressions
void print_expression_stack(Expression_stack *exp_stack) {
    Expression_stack *current = exp_stack;
    while ( !is_empty_expression_stack(current) ) {
        printf(" Value: %d , Opé: %c \n", current->value, current->operator ); // Affiche la valeur et l'opérateur de l'expression courante
        current = current->next_expression; // Passe à l'expression suivante
    }
}
