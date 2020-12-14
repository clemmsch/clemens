#ifndef CLES_PARSER_H
#define CLES_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"   
#include <stdint.h>
#include <limits.h>


enum _ParserStatus {
    PARSER_SUCESS,
    PARSER_SYNTAX_ERROR,
    PARSER_ERROR,
};
typedef enum _ParserStatus ParserStatus;

ParserStatus startParser(TokenList* list, char* source);
uint32_t getNumberFromParser(const char* buf);
TokenInst getInstructionFromParser(const char* buf);




#endif 