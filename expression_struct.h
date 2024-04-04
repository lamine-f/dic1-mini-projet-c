typedef struct Expression_stack {
    char operator;
    //-1: NULL VALUE
    int value;
    struct Expression_stack *next_expression;
} Expression_stack;

int evaluate_expression (Expression_stack *exp);
Expression_stack *create_expression_stack();
int is_empty_expression_stack (Expression_stack *exp);
Expression_stack *clear_expression_stack (Expression_stack *exp);
Expression_stack *add_expression(Expression_stack *exp, char operator,  int value);
void print_expression_stack(Expression_stack *exp);