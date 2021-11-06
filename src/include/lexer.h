#ifndef LEXER_H
#define LEXER_H

#include "token.h"

typedef struct LexerStructure {

    char aChar;
    unsigned int i;
    char* sCode;

} lexer_S;

lexer_S* initLexer(char* sCode);

token_S* getNextToken(lexer_S* lexer);

token_S* collectStrings(lexer_S* lexer);

token_S* collectIds(lexer_S* lexer);

token_S* advanceWithToken(lexer_S* lexern, token_S* token);

void advanceChar(lexer_S* lexer);

void skipSpaces(lexer_S* lexer);

char* getStringFromChar(lexer_S* lexer);

#endif