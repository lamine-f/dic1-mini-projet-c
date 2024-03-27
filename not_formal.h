#define IS_MULTIPLICATIVE_OPERATOR(c) ((c == '*') || (c == '/'))
#define IS_ASSOCIATIVE_OPERATOR(c) ((c == '+') || (c == '-'))
#define IS_DIGIT(c) ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') )
#define IS_START_FACTOR(c) ((c == '('))
#define IS_END_FACTOR(c) ((c == ')'))



bool IS_NUMBER (char *str);
bool IS_EXPRESSION(char *str);
bool IS_FACTOR (char *str);
