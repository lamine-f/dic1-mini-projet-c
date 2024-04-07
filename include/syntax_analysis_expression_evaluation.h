#ifndef SYNTAX_ANALYSIS_EXPRESSION_EVAL_H_INCLUDED
#define SYNTAX_ANALYSIS_EXPRESSION_EVAL_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "term_struct.h"
#include "expression_struct.h"
void arithmetic_resolver ();
void parser ();
int expression ();
int term ();
int factor ();
int number ();
#endif