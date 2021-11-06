#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "include/lexer.h"
#include "include/token.h"

lexer_S* initLexer(char* sCode) 
{
    lexer_S* lexer = calloc(1, sizeof(struct LexerStructure));
    lexer -> sCode = sCode;
    lexer -> i = 0;
    lexer -> aChar = sCode[lexer -> i];

    return lexer;
}

token_S* getNextToken(lexer_S* lexer) 
{
    while (lexer -> aChar != '\0' && lexer -> i < strlen(lexer -> sCode)) {
        if (lexer -> aChar == ' ' || lexer -> aChar == 10) 
        {
            skipSpaces(lexer);
        }

        if (isalnum(lexer -> aChar)) {
            return collectIds(lexer);
        }

        if (lexer -> aChar == '"')
        {
            return collectStrings(lexer); 
        }

        switch (lexer -> aChar)
        {
            case '=': return advanceWithToken(lexer, initToken(TOKEN_EQUALS, getStringFromChar(lexer))); break;
            case ';': return advanceWithToken(lexer, initToken(TOKEN_SCOLUMN, getStringFromChar(lexer))); break;
            case '(': return advanceWithToken(lexer, initToken(TOKEN_LPARENT, getStringFromChar(lexer))); break;
            case ')': return advanceWithToken(lexer, initToken(TOKEN_RPARENT, getStringFromChar(lexer))); break;
        }
    }
    return (void*)0;
}

token_S* collectStrings(lexer_S* lexer)
{
    advanceChar(lexer);

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (lexer -> aChar != '"')
    {
        char* string = getStringFromChar(lexer);
        value = realloc(value, (strlen(value) + strlen(string) + 1) * sizeof(char));
        strcat(value, string);
        
        advanceChar(lexer);
    }

    advanceChar(lexer);

    return initToken(TOKEN_STRING, value);

}

token_S* collectIds(lexer_S* lexer)
{

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (isalnum(lexer -> aChar))
    {
        char* string = getStringFromChar(lexer);
        value = realloc(value, (strlen(value) + strlen(string) + 1) * sizeof(char));
        strcat(value, string);

        advanceChar(lexer);
    }


    return initToken(TOKEN_ID, value);
}


token_S* advanceWithToken(lexer_S* lexer, token_S* token)
{
    advanceChar(lexer);
    return token;
}

void advanceChar(lexer_S* lexer){
    if (lexer -> aChar != '\0' && lexer -> i < strlen(lexer -> sCode))
    {
        lexer -> i += 1;
        lexer -> aChar = lexer -> sCode[lexer -> i];
    }
}

void skipSpaces(lexer_S* lexer)
{
    while (lexer -> aChar == ' ' || lexer -> aChar == 10) 
    {
        advanceChar(lexer);
    }
}

char* getStringFromChar(lexer_S* lexer)
{
    char* string = calloc(2, sizeof(char));
    string[0] = lexer -> aChar;
    string[1] = '\0';

    return string;
}
