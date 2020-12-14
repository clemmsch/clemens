#include "../include/parser.h"


void startParser(TokenList* list, char* source) {
    char lex[256];
    int lexi = 0;
    int i = 0;
    int line = 1;

    while (1) 
    {
        memset(lex, 0, 256);

        while(source[i] != ' ' && source[i] != '\n' && source[i] == '\0' && source[i] != '(' || source[i] != ')') {
            lex[lexi++] = source[i++];
        }
        lex[lexi] = '\0';

        // A Hash implies a numerical constant
        if (lex[0] == '#') {
            int num = getNumberFromParser(lex);
            addToTokenList(list, createToken(NUMBER, num, line));
        }


    }

}