#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include "terme.h"
#include "not_formal.h"


/** A SORTIR */

bool IS_NUMBER (char *str) {
    for (int i=0; i<strlen(str); i++)
        if (!IS_DIGIT(*(str+i))) return false;
    return true;
}


bool IS_EXPRESSION(char *str) {
    return true;
}

bool IS_FACTOR (char *str) {
    if ( IS_NUMBER(str) ) return true;
    int str_len = strlen(str);
    char first_character = *str;
    char last_character = *(str+str_len-1);
    if (!IS_START_FACTOR(first_character)) return false;
    if (!IS_END_FACTOR(last_character)) return false;
    char *expression_str = malloc(sizeof(char)*str_len-2);
    int j=0;
    for (int i=1; i<str_len-1; i++ ) 
        *(expression_str+j++) = *(str+i); 
    return IS_EXPRESSION(expression_str);
}

/*---------------------------*/


void printTerme (terme t, int id) {
    if (id == 1) {
        // printf("\n");
        printf("[%s] [%c]",
            t.factor, 
            t.factor_terme.multiplicative_operator
        );

    }else {
        printf("[%s]", t.factor);
    }
    printf("\n");

}

factor_terme string_factor_terme_mapping (char *str) {
    int str_len = strlen(str);
    int j=0;
    char *buffer = calloc(sizeof(char), 50);
    bool is_get_factor = false;
    factor_terme factor_terme;
    for (int i=0; i<str_len; i++){
        if ( !is_get_factor && IS_MULTIPLICATIVE_OPERATOR(*(str+i))) {
            factor_terme.multiplicative_operator = *(str+i);
            strcpy(factor_terme.factor, buffer);
            buffer = calloc(sizeof(char), 50);
            j=0;
            is_get_factor = true;
            continue;
        }
        buffer[j++] = str[i];
        if (is_get_factor && i == str_len -1 ) {
            terme terme = string_terme_mapping(buffer);
            factor_terme.terme = &terme;
            factor_terme.terme->factor_terme.multiplicative_operator = '\0';
            factor_terme.terme->factor_terme.terme = NULL;
            factor_terme.terme->factor_terme.terme. = '\0';
        }
    }
    return factor_terme;
}

terme string_terme_mapping (char *str) {
    // 2 * 2 * 2
    int str_len = strlen(str);
    bool is_set_multiplicative_operator = false;
    for (int i=0; i<str_len; i++){
        if ( IS_MULTIPLICATIVE_OPERATOR(*(str+i))) {
            is_set_multiplicative_operator = true;
            break;
        }
    }

    terme result;
    if (is_set_multiplicative_operator) {
        factor_terme factor_terme_value = string_factor_terme_mapping(str);
        result.factor_terme = factor_terme_value;
    }else {
        strcpy(result.factor, str);
    }
    return result;
}

bool is_factor_terme_valid (factor_terme f) {
    printf("is_factor %d, f=%s\n", IS_FACTOR(f.factor), f.factor);
    if ( IS_FACTOR(f.factor) ) {
        printf("is_mult %d, c=%c\n", IS_MULTIPLICATIVE_OPERATOR(f.multiplicative_operator), f.multiplicative_operator);
        
        if ( f.multiplicative_operator == '\0' ) {
            return true;
        
        }else if ( IS_MULTIPLICATIVE_OPERATOR(f.multiplicative_operator) ) {
            if ( f.terme->factor_terme.terme == NULL ) return true;
            // printf("%c", f.terme->factor_terme.multiplicative_operator);
            return  is_terme_valid(*f.terme);
        }
    }
    return false;
}


bool is_terme_valid (terme t) {
    return is_factor_terme_valid(t.factor_terme);
}


bool IS_TERME (char *str) {
    terme terme = string_terme_mapping(str);
    return is_terme_valid(terme);
}

