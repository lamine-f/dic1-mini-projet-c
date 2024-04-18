#include "../includes/utils.h"
#include "../includes/session.h"
#include "../includes/syntax_analysis_expression_evaluation.h"

// Définition des macros pour simplifier le code
#define is_multiplicative_operator(c) ((c == '*') || (c == '/'))
#define is_additive_operator(c) ((c == '+') || (c == '-'))
#define is_digit(c) ( (c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') )
#define is_start_factor(c) ((c == '('))
#define is_end_factor(c) ((c == ')'))
#define is_expression_termination_character(c) (( c == '='))
#define is_stop_session_character(c) (( c == '.'))

// Résout une expression arithmétique
void arithmetic_resolver () {
    start_session(); // Commence une session pour résoudre l'expression arithmétique
}

// Analyse une expression
void parser () {
    read_next_character(); // Lit le prochain caractère non-blanc
    if ( is_stop_session_character(read_character) ) {
        stop_session(); // Si le caractère lu est un point, arrête la session
    }else {
        int expression_result = expression(); // Sinon, évalue l'expression
        if ( is_expression_termination_character(read_character) ) {
            // Si le caractère lu est un signe égal
            if ( getchar() == '\n' ) {
                print_result(expression_result); // S'il n'y a pas de caractère aprés le signe égal, imprime le résultat de l'expression
            }else {
                abort_process(-1, "caractère trouvé aprés le caractère de terminaison"); // Sinon, termine le processus avec un message d'erreur
            }
        }
        else if ( is_end_factor(read_character) ) {
            abort_process(-1, "parenthèse non ouverte"); // Sinon, termine le processus avec un message d'erreur
        }else {
            abort_process(-1, "symbole terminal non reconnu"); // Sinon, termine le processus avec un message d'erreur
        }
    }
}

// Évalue une expression
int expression () {
    int term_result = term(); // Évalue un terme
    int result = term_result;
    if ( ( is_additive_operator((read_character)) ) ) {
        char operator = read_character;
        read_next_character(); // Lit le prochain caractère non-blanc
        int value = expression();
        switch (operator) {
            case '+':
                result += value; // Si l'opérateur est '+', ajoute la valeur à result
                break;
            case '-':
                result -= value; // Si l'opérateur est '-', soustrait la valeur à result
                break;
            default:
                break;
        }
    }
    return result; // Retourne le résultat de l'expression
}

// Évalue un terme
int term () {
    int factor_result = factor(); // Évalue un facteur
    int result = factor_result;
    if ( is_multiplicative_operator( (read_character) ) ) {
        char operator = read_character;
        read_next_character(); // Lit le prochain caractère non-blanc
        int value = term();
        switch (operator) {
            case '*':
                result *= value; // Si l'opérateur est '*', multiplie la valeur par result
                break;
            case '/':
                if (value == 0) abort_process(-2, "division par zéro"); // Si la valeur est 0, arrête le processus avec un message d'erreur
                result /= value; // Si l'opérateur est '/', divise result par la valeur
                break;
            default:
                break;
        }
    }
    return result; // Retourne le résultat du terme
}

// Évalue un facteur
int factor () {
    int result;
    if ( is_digit(read_character) ){
        result = number(); // Si le caractère lu est un chiffre, convertit le chiffre en nombre
    }else if ( is_start_factor(read_character) ) {
        read_next_character(); // Si le caractère lu est une parenthèse ouvrante, lit le prochain caractère
        result = expression(); // Évalue l'expression
        if ( is_end_factor(read_character) ) {
            read_next_character(); // Si le caractère lu est une parenthèse fermante, lit le prochain caractère
        } else {
            abort_process(-1, "parenthèse non fermée"); // Sinon, termine le processus avec un message d'erreur
        }
    }else {
        abort_process(-1, "symbole terminal non reconnu"); // Si le caractère lu n'est ni un chiffre ni une parenthèse ouvrante, termine le processus avec un message d'erreur
    }
    return result; // Retourne le résultat du facteur
}

// Évalue un nombre
int number () {
    char str_number[50]={'0'};
    int len=0;
    while ( is_digit(read_character) ) {
        str_number[len++] = read_character; // Si le caractère lu est un chiffre, l'ajoute à la chaîne de caractères
        read_next_character(); // Lit le prochain caractère
    }
    return str_to_number(str_number, len); // Convertit la chaîne de caractères en nombre et retourne le nombre
}