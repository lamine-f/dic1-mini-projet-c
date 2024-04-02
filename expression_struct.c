#include "not_formal.h"

Expression_tree *create_expression_tree () {
    Expression_tree *exp_tree = malloc(sizeof(*exp_tree));
    exp_tree->right_expression_tree = NULL;
    exp_tree->parent_expression_tree = NULL;
    exp_tree->left_value = -1;
    return exp_tree;
}

Expression_tree *set_expression_tree_value(Expression_tree *exp_tree, int value) {
    if (is_empty_expression_tree(exp_tree)) {
        exp_tree = malloc(sizeof(*exp_tree));    
    }
    exp_tree->left_value = value;
    return exp_tree;    
}

Expression_tree *set_expression_tree_operator(Expression_tree *exp_tree, char operator) {
    if (is_empty_expression_tree(exp_tree)) exp_tree = malloc(sizeof(*exp_tree));
    exp_tree->operator = operator;
    return exp_tree;    
}

Expression_tree *create_right_expression_tree(Expression_tree *exp_tree) {
    if (exp_tree->right_expression_tree == NULL) {
        exp_tree->right_expression_tree = malloc(sizeof(*exp_tree));
        exp_tree->right_expression_tree->parent_expression_tree = exp_tree;
    }else {
        printf("DEV: RIGHT EXPRESSION ALREADY EXIST\n");
    }
    return exp_tree;    
}

Expression_tree *add_new_right_expression_tree(Expression_tree *exp_tree_dest, Expression_tree *exp_tree) {
    if ( exp_tree_dest->right_expression_tree != NULL ) {
        printf("DEV: RIGHT EXPRESSION ALREADY EXIST\n");
    }else {
        exp_tree_dest->right_expression_tree = exp_tree;
        exp_tree_dest->right_expression_tree->parent_expression_tree = exp_tree_dest;
    }
    return exp_tree_dest; 
}

void print_expression_tree(Expression_tree *exp_tree) {
    Expression_tree *current = exp_tree;
    if ( is_empty_expression_tree(current) ) {
        return;
    }

    if ( !is_empty_expression_tree(current->parent_expression_tree) ) {
        printf("(%d) -> %c(%d)\n", current->parent_expression_tree->left_value, current->operator, current->left_value);
    }else {
        printf("%c(%d)\n", current->operator, current->left_value);
    }

    if ( !is_empty_expression_tree(current->right_expression_tree) ) {
        print_expression_tree(current->right_expression_tree);
    }
}

int is_empty_expression_tree (Expression_tree *exp_tree) {
    return (exp_tree == NULL);
}