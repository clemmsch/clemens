#include "../include/parser.h"

// FIXME There are Memory leaks in here
// TODO Make the inpur const
ParserStatus startParser(TokenList* list, char* source) {
    char lex[256];
    int lexi = 0;
    int i = 0;
    int line = 1;

    // TODO Fix looping while nullk
    while (1) 
    {
        // memset(lex, 0, 256);

        while(source[i] != ' ' && source[i] != '\n' && source[i] != '\0') {
            lex[lexi++] = source[i++];
        }
        lex[lexi] = '\0';

        // A Hash implies a numerical constant
        if (lex[0] == '#') {
            int num = getNumberFromParser(lex);
            printf("NUMBER: %d\n", num);
            addToTokenList(list, createToken(NUMBER, num, line));
        }

        // Must be an instruction
        else {
            int inst = getInstructionFromParser(lex);
//            printf("Inst: '%d'\n", inst);
            // FIXME Make this better
            printf("Lex: %s\n", lex);
            if (inst = 0) {
                printf("INST: %s\n", lex);
                addToTokenList(list, createToken(INST, inst, line));
           } else {
               // TODO Add line to error
                printf(" C001 | Syntax error: no such instruction '%s'\n", lex);
                return PARSER_SYNTAX_ERROR;
           }
        }


        // If new line increment line
        if (source[i] == '\n') {
            line++;
        }

        // End of file
        else if (source[i] == '\0') {
            break;
        }

        // Reset lexi
        lexi = 0;

        // Increment
        i++;

    }

    return PARSER_SUCESS;
}

uint32_t getNumberFromParser(const char* buf) {
    long num = atoi(&buf[1]);
    return (num <= UINT32_MAX) ? num : 0;
}

// TODO Add more
TokenInst getInstructionFromParser(const char* buf) {
    // TODO Replace with switch
    if (strcmp(buf, "push") == 0)
        return PUSH;
    if (strcmp(buf, "add") == 0)
        return ADD;
    if (strcmp(buf, "hlt") == 0)
        return HLT;
    return (TokenInst) -1;
}