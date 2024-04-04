#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED
#include <stdbool.h>
extern bool SESSION;
void start_session();
void stop_session();
void abort_process(int status_code, char* message);
#endif