#include <stdio.h>

#include "include/lexer.h"

int main(int argc, char* argv[]) 
{
    lexer_S* lexer = initLexer(
        "var name = \"Hello\";\n"
        "print(name);\n"
    );
    token_S* token = (void*)0;
    while((token = getNextToken(lexer)) != (void*)0)
    {
        printf("TOKEN(%d, %s)\n", token -> type, token -> value);
    }
    return 0;
}