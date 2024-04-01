#define is_blank_character(c) ((c == ' ') || (c == ' '))
#define is_multiplicative_operator(c) ((c == '*') || (c == '/'))
#define is_additive_operator(c) ((c == '+') || (c == '-'))
#define is_digit(c) ( (c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') )

#define is_start_factor(c) ((c == '('))
#define is_end_factor(c) ((c == ')'))



#define is_termination_character(c) (( c == '='))



void clear_buffer ();
void read_next_character ();
void print_error_message (char *str);
void parser();
int expression ();
int term ();
int factor ();
int number ();