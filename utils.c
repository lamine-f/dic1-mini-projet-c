#include "utils.h"

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