#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "term_struct.h"
#include "expression_struct.h"

void arithmetic_resolver ();
void parser ();
int expression ();
int term ();
int factor ();
int number ();