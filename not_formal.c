#include "not_formal.h"

char readed_charater;

void clear_buffer () {
    int c = 0;
    while (c != '\n' && c != EOF) 
        c = getchar();
}

void read_next_character () {
    while ( isblank(readed_charater = getchar()) );
}

void print_error_message (char *str) {
    printf("la syntaxe de l’expression est erronée: %s\n", str);
}

void print_result (int value) {
    printf(
        "la syntaxe de l’expression est correcte"
        "\nsa valeur est %d\n",
        value);
} 

/*
    [TODO COMMENT THE PROJECT]
*/

Expression_tree expre;
//2+2
void parser () {
    read_next_character();
    int expression_result = expression();
    if ( is_termination_character(readed_charater) )
        print_result(expression_result);
    else 
        print_error_message("symbole terminal non reconu");
}

int expression () {
    int term_result = term();
    Expression_tree *exp_tree = create_expression_tree();    
    Expression_tree *current = exp_tree;
    while ( is_additive_operator((readed_charater)) ) {
        set_expression_tree_operator(current, readed_charater);
        set_expression_tree_value(current, term_result);
        create_right_expression_tree(current);
        read_next_character();
        term_result = term();
        current = current->right_expression_tree;
    }


    //process
    printf("EXPRESSIONS \n");
    print_expression_tree(exp_tree);

    return 0;
}

int term () {
    int factor_result = factor();
    Term_stack *term_stack = create_term_stack();
    while ( is_multiplicative_operator( (readed_charater) ) ) {
        term_stack = add_new_next_term(term_stack, readed_charater, factor_result);
        printf("cc\n");
        factor_result=factor();
        // term_stack = add_new_next_term(term_stack, '-', factor_result);
    }

    printf("TERMS \n");
    // print_term_stack(term_stack);
    // int res = evaluate_term(term_stack, 1);
    //proccess

    // printf("RES: %d\n", res);

    // clear_term_stack(term_stack);

    return 0;
}

int factor () {
    int result;
    if ( is_digit(readed_charater) ){
        result = number();
    }else if ( is_start_factor(readed_charater) ) {
        read_next_character();
        result = expression();
        if ( is_end_factor(readed_charater) )
            read_next_character();
        else
            print_error_message("parenthse non fermé");
    }
    return result;
}

int number () {
    char str_number[50]={'0'};
    int i=0;
    while ( is_digit(readed_charater) ) {
        str_number[i++] = readed_charater;
        read_next_character();
    }
    return atoi(str_number);
}