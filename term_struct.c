#include "not_formal.h"

int evaluate_term (Term_stack *term_stack, int acc) {
    if ( is_term_stack_empty(term_stack) ) {
        return acc;
    }


    switch (term_stack->operator) {
        case '*' :
            /* code */
            printf("cc %d \n", acc * term_stack->value);
            return evaluate_term(term_stack->next_term, acc*term_stack->value);
            break;
        
        case '/' :
            /* code */
            return evaluate_term(term_stack->next_term, acc/term_stack->value);
            break;
        

        default:
            break;
    }


    // if ( !is_term_stack_empty(current->previous_term) ) {
        
    //     printf("(%d) -> (%d)\n", current->previous_term->value, current->value);
    // }else {
    //     printf("(%d)\n", current->value);
    // }

    // if ( !is_term_stack_empty(current->next_term) ) {
    //     print_term_stack(current->next_term);
    // }

}

Term_stack *create_term_stack() {
    return NULL;
}

Term_stack *set_term_stack_value(Term_stack *term_stack, int value) {
    if (is_term_stack_empty(term_stack)) {
        term_stack = malloc(sizeof(*term_stack));    
    }
    term_stack->value = value;
    return term_stack; 
}

Term_stack *set_term_stack_operator(Term_stack *term_stack, char operator) {
    if (is_term_stack_empty(term_stack)) {
        term_stack = malloc(sizeof(*term_stack));    
    }
    term_stack->operator = operator;
    return term_stack; 
}

Term_stack *create_next_term(Term_stack *term_stack) {
    if (term_stack->next_term == NULL) {
        term_stack->next_term = malloc(sizeof(*term_stack));
        term_stack->next_term->previous_term = term_stack;
    }else {
        printf("DEV: RIGHT EXPRESSION ALREADY EXIST\n");
    }
    return term_stack;  
}

Term_stack *add_new_next_term(Term_stack *term_stack_dest, char operator, int value) {

    Term_stack *t_s = malloc(sizeof(*t_s));
    // term_stack_dest->previous_term = t_s;

    if ( !is_term_stack_empty(term_stack_dest) ) {
        term_stack_dest->previous_term = t_s;
    }

    t_s->next_term=term_stack_dest;
    t_s->operator = operator;
    t_s->value = value;
    t_s->previous_term = NULL;

    return t_s;
}

void print_term_stack(Term_stack *term_stack) {
    Term_stack *current = term_stack;
    
    while ( !is_term_stack_empty(current) ) {
        printf(" Value: %d , Opé: %c \n", current->value, current->operator );
        current = current->next_term;
    }
    
}

int is_term_stack_empty (Term_stack *term_stack) {
    return (term_stack == NULL);
}

Term_stack *clear_term_stack (Term_stack *term_stack) {
    Term_stack *s_t;
    if ( is_term_stack_empty(s_t) ) return NULL;
    s_t = term_stack->next_term;
    free(term_stack);
    return clear_term_stack(s_t);    
}