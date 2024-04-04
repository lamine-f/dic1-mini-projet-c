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
int str_to_number (char *str, int len);
#endif