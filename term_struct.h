
typedef struct Term_stack {
    //-1: NULL VALUE
    int value;
    struct Term_stack *next_term;
    struct Term_stack *previous_term;
    char operator;
} Term_stack ;

int evaluate_term (Term_stack *term_stack, int acc);
Term_stack *create_term_stack();
Term_stack *set_term_stack_value(Term_stack *term_stack, int value);
Term_stack *set_term_stack_operator(Term_stack *term_stack, char operator);
Term_stack *create_next_term(Term_stack *term_stack);
Term_stack *add_new_next_term(Term_stack *term_stack_dest, char operator, int value);
void print_term_stack(Term_stack *term_stack);
int is_term_stack_empty (Term_stack *term_stack);
Term_stack *clear_term_stack (Term_stack *term_stack);