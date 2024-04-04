#include "../include/term_struct.h"
#include "../include/session.h"

int evaluate_term ( Term_stack *term_stack ) {
    Term_stack *current = term_stack;
    int previous_value = 1;
    int value = current->value;
    while ( !is_empty_term_stack(current) ) {
        int current_value = current->value;
        switch (current->operator) {
            case '*':
                value = current_value * previous_value;
                break;
            case '/':
                if (previous_value == 0) abort_process(-2, "division par zéro");
                value = current_value / previous_value;
                break;
            default:
                break;
        }
        previous_value = value;
        current = current->next_term;
    }
    return value;
}

Term_stack *create_term_stack() {
    return NULL;
}

int is_empty_term_stack (Term_stack *term_stack) {
    return (term_stack == NULL);
}

Term_stack *clear_term_stack (Term_stack *term_stack) {
    Term_stack *s_t;
    if ( is_empty_term_stack(s_t) ) return NULL;
    s_t = term_stack->next_term;
    free(term_stack);
    return clear_term_stack(s_t);
}

Term_stack *add_term(Term_stack *term_stack, char operator, int value) {
    Term_stack *t_s = malloc(sizeof(*t_s));
    t_s->next_term=term_stack;
    t_s->operator = operator;
    t_s->value = value;
    return t_s;
}

void print_term_stack(Term_stack *term_stack) {
    Term_stack *current = term_stack;
    while ( !is_empty_term_stack(current) ) {
        printf(" Value: %d , Opé: %c \n", current->value, current->operator );
        current = current->next_term;
    }
}