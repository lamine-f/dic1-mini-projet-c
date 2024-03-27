
union terme;

typedef struct factor_terme {
    char factor[50];
    char multiplicative_operator;
    union terme *terme;
}factor_terme;

typedef union terme  {
    factor_terme factor_terme;
    char factor[50];
} terme;


void printTerme (terme t, int id);
factor_terme string_factor_terme_mapping (char *str);
terme string_terme_mapping (char *str);
factor_terme string_factor_terme_mapping (char *str);
terme string_terme_mapping (char *str);
bool is_terme_valid (terme t);
bool is_factor_terme_valid (factor_terme f);
bool IS_TERME (char *str);

