#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "not_formal.h"



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
