// session.h
#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern bool SESSION; // Déclaration de la variable globale SESSION

// Prototypes des fonctions
void start_session(); // Démarre une session
void stop_session(); // Arrête une session
void abort_process(int status_code, char* message); // Termine un processus avec un code d'état et un message

#endif