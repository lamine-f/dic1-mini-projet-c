#include "../include/utils.h"
#include "../include/session.h"
#include "../include/syntax_analysis_expression_evaluation.h"

#define is_blank_character(c) ((c == ' ') || (c == ' '))
#define is_multiplicative_operator(c) ((c == '*') || (c == '/'))
#define is_additive_operator(c) ((c == '+') || (c == '-'))
#define is_digit(c) ( (c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') )
#define is_start_factor(c) ((c == '('))
#define is_end_factor(c) ((c == ')'))
#define is_termination_character(c) (( c == '='))
#define is_stop_session_character(c) (( c == '.'))

void arithmetic_resolver () {
    start_session();
}

void parser () {
    read_next_character();
    if ( is_stop_session_character(read_character) ) {
        stop_session();
    }else {
        int expression_result = expression();
        if ( is_termination_character(read_character) )
            print_result(expression_result);
        else {
            abort_process(-1, "symbole terminal non reconu");
        }
    }
}

int expression () {
    int term_result = term();
    int result = term_result;
    if ( ( is_additive_operator((read_character)) ) ) {
        Expression_stack *exp_stack = create_expression_stack();
        exp_stack = add_expression(exp_stack, read_character, term_result);
        while ( is_additive_operator((read_character)) ) {
            read_next_character();
            term_result = term();
            exp_stack = add_expression(exp_stack, read_character, term_result);
        }
        result = evaluate_expression(exp_stack);
        clear_expression_stack(exp_stack);
    }
    return result;
}

int term () {
    int factor_result = factor();
    int result = factor_result;
    if ( is_multiplicative_operator( (read_character) ) ) {
        Term_stack *term_stack = create_term_stack();
        term_stack = add_term(term_stack, read_character, factor_result);
        while ( is_multiplicative_operator( (read_character) ) ) {
            read_next_character();
            factor_result=factor();
            term_stack = add_term(term_stack, read_character, factor_result);
        }
        result = evaluate_term(term_stack);
        clear_term_stack(term_stack);
    }
     return result;
}

int factor () {
    int result;
    if ( is_digit(read_character) ){
        result = number();
    }else if ( is_start_factor(read_character) ) {
        read_next_character();
        result = expression();
        if ( is_end_factor(read_character) ) {
            read_next_character();
        } else {
            abort_process(-1, "parenthse non fermée");
        }

    }else {
        abort_process(-1, "facteur incorrect");
    }
    return result;
}

int number () {
    char str_number[50]={'0'};
    int len=0;
    while ( is_digit(read_character) ) {
        str_number[len++] = read_character;
        read_next_character();
    }
    return str_to_number(str_number, len);
}