#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "syntax_analysis_expression_evaluation.h"

char read_character;

void clear_buffer () {
    int c = 0;
    while (c != '\n' && c != EOF) 
        c = getchar();
}

void read_next_character () {
    while ( isblank(read_character = getchar()) );
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
void parser () {
    read_next_character();
    int value = expression();
    if ( is_termination_character(read_character) )
        print_result(value);
    else 
        print_error_message("symbole terminal non reconu");
}

int expression () {
    int value = term();
    char operator;
    while ( is_additive_operator((operator = read_character)) ) {
        read_next_character();
        switch (operator) {
            case '+':
                value+=term();
                break;
            case '-':
                value-=term();
                break;
            default:
                break;
        }
    }
    return value;
}

int term () {
    int value = factor();
    char operator;
    while ( is_multiplicative_operator( (operator = read_character) ) ) {
        read_next_character();
        switch (operator) {
            case '*':
                value*=factor();
                break;
            case '/':
                value/=factor();
                break;
            default:
                break;
        }
    }
    return value;
}

int factor () {
    int value;
    if ( is_digit(read_character) ){
        value = number();
    }else if ( is_start_factor(read_character) ) {
        read_next_character();
        value = expression();
        if ( is_end_factor(read_character) )
            read_next_character();
        else
            print_error_message("parenthse non fermé");
    }
    return value;
}


int number () {
    char str_number[50]={'0'};
    int i=0;
    while ( is_digit(read_character) ) {
        str_number[i++] = read_character;
        read_next_character();
    }
    return atoi(str_number);
}