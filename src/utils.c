#include "../includes/utils.h"

char read_character;

void clear_buffer () {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}

void init_read_character() {
    clear_buffer();
}

void read_next_character () {
    while ( isblank(read_character = getchar()) );
}

void print_error_message (char *prefix, char *message) {
    printf("%s: %s\n", prefix, message);
}

void print_result (int value) {
    printf(
            "la syntaxe de l’expression est correcte"
            "\nsa valeur est %d\n",
            value
    );
}

int char_to_digit (char c) {
    switch (c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}

int power (int number, int pow_value) {
    if (pow_value == 0) return 1;
    return number*power(number, pow_value-1);
}

int str_to_number (char *str, int len) {
    int result = 0;
    for(int i=0; i<len; i++) {
        result+= char_to_digit(str[i]) * power(10, len-i-1);
    }
    return result;
}
