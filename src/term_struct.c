// term_struct.c
#include "../includes/term_struct.h"
#include "../includes/session.h"

// Évalue un terme
int evaluate_term ( Term_stack *term_stack ) {
    Term_stack *current = term_stack;
    int previous_value = 1;
    int value = current->value;
    while ( !is_empty_term_stack(current) ) {
        int current_value = current->value;
        switch (current->operator) {
            case '*':
                value = current_value * previous_value; // Si l'opérateur est '*', multiplie la valeur précédente par la valeur courante
                break;
            case '/':
                if (previous_value == 0) abort_process(-2, "division par zéro"); // Si la valeur précédente est 0, arrête le processus avec un message d'erreur
                value = current_value / previous_value; // Si l'opérateur est '/', divise la valeur courante par la valeur précédente
                break;
            default:
                break;
        }
        previous_value = value;
        current = current->next_term;
    }
    return value; // Retourne la valeur finale du terme
}

// Crée une nouvelle pile de termes
Term_stack *create_term_stack() {
    return NULL; // Retourne NULL car la pile est initialement vide
}

// Vérifie si la pile de termes est vide
int is_empty_term_stack (Term_stack *term_stack) {
    return (term_stack == NULL); // Retourne vrai si la pile est vide, faux sinon
}

// Vide la pile de termes
Term_stack *clear_term_stack (Term_stack *term_stack) {
    Term_stack *s_t;
    if ( is_empty_term_stack(s_t) ) return NULL;
    s_t = term_stack->next_term;
    free(term_stack); // Libère la mémoire allouée au terme courant
    return clear_term_stack(s_t); // Appelle récursivement la fonction pour le reste de la pile
}

// Ajoute un terme à la pile
Term_stack *add_term(Term_stack *term_stack, char operator, int value) {
    Term_stack *t_s = malloc(sizeof(*t_s)); // Alloue de la mémoire pour le nouveau terme
    t_s->next_term=term_stack; // Fait pointer le nouveau terme vers le terme précédent
    t_s->operator = operator; // Affecte l'opérateur au nouveau terme
    t_s->value = value; // Affecte la valeur au nouveau terme
    return t_s; // Retourne la nouvelle pile de termes
}

// Affiche la pile de termes
void print_term_stack(Term_stack *term_stack) {
    Term_stack *current = term_stack;
    while ( !is_empty_term_stack(current) ) {
        printf(" Value: %d , Opé: %c \n", current->value, current->operator ); // Affiche la valeur et l'opérateur du terme courant
        current = current->next_term; // Passe au terme suivant
    }
}
