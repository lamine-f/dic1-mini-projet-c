#include "../includes/expression_struct.h"

int evaluate_expression (Expression_stack *exp_stack) {
    Expression_stack *current = exp_stack;
    int previous_value = 0;
    int value = current->value;
    while ( !is_empty_expression_stack(current) ) {
        int current_value = current->value;
        switch (current->operator) {
            case '+':
                value = current_value + previous_value;
                break;
            case '-':
                value = current_value - previous_value;
                break;
            default:
                break;
        }
        previous_value = value;
        current = current->next_expression;
    }
    return value;
}

Expression_stack *clear_expression_stack (Expression_stack *exp_stack) {
    if (is_empty_expression_stack(exp_stack) )
        return NULL;
    Expression_stack *next_exp_stack = exp_stack->next_expression;
    free(exp_stack);
    return clear_expression_stack(next_exp_stack);
}

Expression_stack *create_expression_stack () {
    return NULL;
}

int is_empty_expression_stack (Expression_stack *exp_stack) {
    return (exp_stack == NULL);
}

Expression_stack *add_expression(Expression_stack *exp_stack, char operator, int value) {
    Expression_stack *new_exp_stack = malloc(sizeof(*new_exp_stack));
    new_exp_stack->operator = operator;
    new_exp_stack->value = value;
    new_exp_stack->next_expression = exp_stack;
    return new_exp_stack;
}

void print_expression_stack(Expression_stack *exp_stack) {
    Expression_stack *current = exp_stack;
    while ( !is_empty_expression_stack(current) ) {
        printf(" Value: %d , Opé: %c \n", current->value, current->operator );
        current = current->next_expression;
    }
}