typedef struct Expression_tree {
    char operator;
    //-1: NULL VALUE
    int left_value;
    struct Expression_tree *right_expression_tree ;
    struct Expression_tree *parent_expression_tree ;
} Expression_tree;


int evaluate_expression (Expression_tree *expre);
Expression_tree *create_expression_tree();
Expression_tree *set_expression_tree_value(Expression_tree *exp_tree, int value);
Expression_tree *set_expression_tree_operator(Expression_tree *exp_tree, char operator);
Expression_tree *create_right_expression_tree(Expression_tree *exp_tree);
Expression_tree *add_new_right_expression_tree(Expression_tree *exp_tree_dest, Expression_tree *exp_tree);
void print_expression_tree(Expression_tree *exp_tree);
int is_empty_expression_tree (Expression_tree *exp_tree);