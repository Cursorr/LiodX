#ifndef TOKEN_H
#define TOKEN_H

typedef struct TokenStructure {

    enum {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_SCOLUMN,
        TOKEN_RPARENT,
        TOKEN_LPARENT
    } type;
    char* value;

} token_S;

token_S* initToken(int type, char* value);

#endif