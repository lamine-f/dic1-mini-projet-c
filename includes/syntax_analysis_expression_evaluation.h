// syntax_analysis_expression_evaluation.h
#ifndef SYNTAX_ANALYSIS_EXPRESSION_EVAL_H_INCLUDED
#define SYNTAX_ANALYSIS_EXPRESSION_EVAL_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "term_struct.h"
#include "expression_struct.h"

// Prototypes des fonctions
void arithmetic_resolver (); // Résout une expression arithmétique
void parser (); // Analyse une expression
int expression (); // Évalue une expression
int term (); // Évalue un terme
int factor (); // Évalue un facteur
int number (); // Convertit une chaîne de caractères en nombre

#endif
