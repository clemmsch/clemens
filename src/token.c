#include "../include/token.h"


Token* createToken(int type, int data, int line) {
    Token* tok = (Token*) malloc(sizeof(Token));
    tok->type = type;
    tok->data = data;
    tok->line = line;
    return tok;
}

void destroyToken(Token* token) {
    free(token);
}


void createTokenList(TokenList* list, int size) {
    list->data = (Token**) malloc(sizeof(Token*) * size);
    list->ptr = 0;
    list->size = size;
}

void addToTokenList(TokenList* list, Token* token) {
    if(list->ptr >= list->size) {
        list->size *= 2;
        list->data = (Token**) realloc(list->data, sizeof(Token*) * list->size);
    }

    list->data[list->ptr++] = token;
}

Token* getTokenFromList(TokenList* list, int index) {
    return list->data[index];
}