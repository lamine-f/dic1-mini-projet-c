// session.c
#include "../includes/session.h"
#include "../includes/syntax_analysis_expression_evaluation.h"
#include "../includes/utils.h"

/*
CODES
    ERROR
        -1: Syntaxe incorrecte
            - (1++=)
        -2: Expression est 'incorrect'
            - (1/0=)

    SUCCESS
         0: Fin de session
 */

bool SESSION = true; // Définition de la variable globale SESSION

// Démarre une session
void start_session () {
    while (SESSION) {
        pid_t process_id = fork(); // Crée un nouveau processus
        //[Executé par le "pére" en cas d"erreur lors de la création d'un nouveau processus]
        if (process_id == -1) {
            //TODO: catch fork error
        }
        //Executé par le processus "fils"
        else if (process_id == 0) {
            while (true) {
                printf("A toi :");
                parser(); // Analyse l'entrée de l'utilisateur
                clear_buffer(); // Vide le buffer d'entrée
            }
        }
        //Executé par le processus "pére"
        else {
            int status;
            waitpid(process_id, &status, 0); // Attend la fin du processus fils
            if (status == 0) {
                SESSION = false; // Si le code d'état est 0, arrête la session
            }
        }
    }
}

// Arrête une session
void stop_session () {
    abort_process(0, "Au revoir..."); // Termine le processus avec un message d'au revoir
}

// Termine un processus avec un code d'état et un message
void abort_process(int code, char *message) {
    switch (code) {
        case -1:
            print_error_message("la syntaxe de l’expression est erronée", message); // Si le code d'état est -1, affiche un message d'erreur de syntaxe
            break;
        case -2:
            print_error_message("la valeur de l’expression est indéfinie", message); // Si le code d'état est -2, affiche un message d'erreur de valeur indéfinie
            break;
        default:
            printf("%s\n", message); // Sinon, affiche le message
    }
    exit(code); // Termine le processus avec le code d'état
}