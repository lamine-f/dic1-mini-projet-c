// syntax_analysis_expression_evaluation.h
#ifndef SYNTAX_ANALYSIS_EXPRESSION_EVAL_H_INCLUDED
#define SYNTAX_ANALYSIS_EXPRESSION_EVAL_H_INCLUDED
#include <stdbool.h>
#include "structs/term_struct.h"
#include "structs/expression_struct.h"

// Prototypes des fonctions
void arithmetic_resolver (); // Résout l'expression arithmétique
void parser (); // Analyse l'expression
int expression (); // Évalue une expression
int term (); // Évalue un terme
int factor (); // Évalue un facteur
int number (); // Évalue un nombre

#endif
