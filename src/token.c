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

void addToTokenList(TokenList* list, Token* token) {
    if(list->ptr >= list->size) {
        list->size *= 2;
        list->data = (Token**) realloc(list->data, sizeof(Token**) * list->size);
    }

    list->data[list->ptr++] = token;
}

Token* getTokenFromList(TokenList* list, int index) {

}