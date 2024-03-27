#include<stdio.h>
#include<stdbool.h>


#define IS_MULTIPLICATIVE_OPERATOR(c) ((c == '*') || (c == '/'))
#define IS_ASSOCIATIVE_OPERATOR(c) ((c == '+') || (c == '-'))
#define IS_DIGIT(c) ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') )

bool IS_NUMBER (char *str) {
    if ( IS_DIGIT(str[0]) ) return true;
    
}

char *read_charater;

int main () {
    char text[] = "1";
    read_charater = &text[0];

    if ( IS_MULTIPLICATIVE_OPERATOR(*read_charater) ) {
        printf("yes it is a muli op\n");
    }

    if ( IS_DIGIT(*read_charater) ) {
        printf("yes it is a digit\n");
    }

    return 0; 
}