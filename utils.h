#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h>
#include <ctype.h>
extern char read_character;
void clear_buffer ();
void read_next_character ();
void init_read_character();
void print_error_message (char *prefix, char *message);
void print_result (int value);
#endif