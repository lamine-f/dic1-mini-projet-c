#include <stdio.h>
#include <stdlib.h>

typedef struct Term_stack {
    int value;
    struct Term_stack *next_term;
    char operator;
} Term_stack ;

int evaluate_term (Term_stack *term_stack);
Term_stack *create_term_stack();
int is_empty_term_stack (Term_stack *term_stack);
Term_stack *clear_term_stack (Term_stack *term_stack);
Term_stack *add_term(Term_stack *term_stack, char operator, int value);
void print_term_stack(Term_stack *term_stack);