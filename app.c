#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "terme.h"
#include "not_formal.h"


char *read_charater;

int main () {
    char text[] = "1";
    read_charater = &text[0];

    if ( IS_MULTIPLICATIVE_OPERATOR('*') ) {
        printf("yes it is a muli op\n");
    }

    if ( IS_DIGIT('1') ) {
        printf("yes it is a digit\n");
    }

    if ( IS_NUMBER("123") ) {
        printf("yes it is a number\n");
    }

    if ( IS_FACTOR("(dds)") ) {
        printf("yes it is a factor\n");
    }

    terme test_terme = string_terme_mapping("45*100");
    printf("%s", test_terme.factor_terme.factor);
    printf("%c", test_terme.factor_terme.multiplicative_operator);
    printf("%s\n", test_terme.factor_terme.terme->factor);


    if ( IS_TERME("45*100") ) {
        printf("yes it is a terme\n");
    }

    // printTerme(test_terme, 1);
    // printTerme(*test_terme.factor_terme.terme, 1);

    return 0; 
}

