#include "include/token.h"

#include <stdlib.h>

token_S* initToken(int type, char* value)
{
    token_S* token = calloc(1, sizeof(struct TokenStructure));
    token -> type = type;
    token -> value = value;
    
    return token;
}
