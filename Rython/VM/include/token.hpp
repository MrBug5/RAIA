#ifndef RYTHON_TOKEN_HPP
#define RYTHON_TOKEN_HPP

struct _Token {
    int data;
    int type;
    int line;
};
typedef struct _Token Token;

Token TokenCreate(int data, int type, int line);
void TokenDelete(Token* token);

struct _TokenList {
    Token** data;
    int ptr;
    int size;
};
typedef struct _TokenList TokenList;

// TokenList* TokenListCreate(int size);
void TokenListAdd(TokenList* list, Token* token);
Token* TokenListGet(TokenList* list, int index);
// void TokenListDelete(TokenList* list);

#endif // RYTHON_TOKEN_HPP
