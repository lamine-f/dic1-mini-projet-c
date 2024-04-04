#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "session.h"
#include "not_formal.h"
#include "utils.h"

/*
ERROR CODE
 * -1 Syntaxe incorrecte => 1++=
 * -2 Expression est 'incorrect' => 1/0=
 *
 * */

bool SESSION = true;
pid_t proccess_id;

void start_session () {

    while (SESSION) {

        proccess_id = fork();

        if (proccess_id == -1) {

        } else if (proccess_id == 0) {
            while (true) {
                printf("A toi :");
                parser();
                clear_buffer();
            }

        }else {
            int status;
            pid_t child_pid = waitpid(proccess_id, &status, 0);
            if (status == 0) {
                SESSION = false;
            }
        }
    }
}

void stop_session () {
    abort_process(0, "");
}

void abort_process(int code, char *message) {
//    clear_buffer();
    switch (code) {
        case -1:
            print_error_message("la syntaxe de l’expression est erronée", message);
        case -2:
            print_error_message("la valeur de l’expression est indéfinie", message);
            break;
        default:
            printf("Au revoir...\n");
    }
    exit(code);
}

