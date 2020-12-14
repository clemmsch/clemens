#ifndef CLES_TOKEN_H
    #define CLES_TOKEN_H

enum _TokenType {
    INST,   // Instruction
    NUMBER,    // Number
};

struct _Token {
    int type;
    int data;
    int line;
};

typedef struct _Token Token;

Token* createToken(int type, int data, int line);
void destroyToken(Token* token);

struct _TokenList {
    Token** data;
    int ptr;
    int size;
};

typedef struct _TokenList TokenList;

TokenList* createTokenList(int size);
void addToTokenList(TokenList* list, Token* token);
Token* getTokenFromList(TokenList* list, int index);
void destroyTokenList(TokenList* list);

#endif // CLES_TOKEN_H