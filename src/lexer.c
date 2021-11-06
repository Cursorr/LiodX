#include "include/lexer.h"
#include <stdlib.h>

lexer_S* initLexer(char* sCode) 
{
    lexer_S* lexer = calloc(1, sizeof(struct LexerStructure));
    lexer -> sCode = sCode;
    lexer -> i = 0;
    lexer -> aChar = sCode[lexer -> i];

    return lexer;
}

lexer_S* getNextToken(lexer_S* lexer) {

}

lexer_S* collectStrings(lexer_S* lexer){

}

void advance(lexer_S* lexer){

}

void skipSpaces(lexer_S* lexer){

}

char* getStringFromChar(lexer_S* lexer){

}
