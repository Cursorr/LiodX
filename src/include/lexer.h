#ifndef LEXER_H
#define LEXER_H

#include "token.h"

typedef struct LexerStructure {

    char aChar;
    unsigned int i;
    char* sCode;

} lexer_S;

lexer_S* initLexer(char* sCode);

lexer_S* getNextToken(lexer_S* lexer);

lexer_S* collectStrings(lexer_S* lexer);

void advance(lexer_S* lexer);

void skipSpaces(lexer_S* lexer);

char* getStringFromChar(lexer_S* lexer);

#endif