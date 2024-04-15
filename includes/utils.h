// utils.h
#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h>
#include <ctype.h>

extern char read_character; // Déclaration de la variable globale read_character

// Prototypes des fonctions
void clear_buffer (); // Vide le buffer d'entrée
void read_next_character (); // Lit le prochain caractère non-blanc
void init_read_character(); // Initialise la lecture des caractères
void print_error_message (char *prefix, char *message); // Affiche un message d'erreur
void print_result (int value); // Affiche le résultat
int str_to_number (char *str, int len); // Convertit une chaîne de caractères en nombre

#endif
