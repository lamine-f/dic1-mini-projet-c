#include "../include/session.h"
#include "../include/syntax_analysis_expression_evaluation.h"
#include "../include/utils.h"

/*
EXIT CODE
    ERROR CODE
        -1: Syntaxe incorrecte => 1++=
        -2: Expression est 'incorrect' => 1/0=

    CODE
         0: Fin de session

 */

bool SESSION = true;
void start_session () {
    while (SESSION) {
        pid_t process_id = fork();
        //[PERE] ERREUR
        if (process_id == -1) {
            //TODO: catch fork error
        }
        //[FILS]
        else if (process_id == 0) {
            while (true) {
                printf("A toi :");
                parser();
                clear_buffer();
            }
        }
        //[PERE]
        else {
            int status;
            waitpid(process_id, &status, 0);
            if (status == 0) {
                SESSION = false;
            }
        }
    }
}

void stop_session () {
    abort_process(0, "Au revoir...");
}

void abort_process(int code, char *message) {
    switch (code) {
        case -1:
            print_error_message("la syntaxe de l’expression est erronée", message);
            break;
        case -2:
            print_error_message("la valeur de l’expression est indéfinie", message);
            break;
        default:
            printf("%s\n", message);
    }
    exit(code);
}