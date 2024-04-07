#include <stdio.h>
#include <stdbool.h>
#include "syntax_analysis_expression_evaluation.h"


int main() {
    while (true)
    {
        printf("A toi :");
        parser();
        clear_buffer();
    }
    return 0;
}
