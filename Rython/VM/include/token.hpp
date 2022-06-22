#ifndef RYTHON_TOKEN_HPP
#define RYTHON_TOKEN_HPP
#include <cstring>

typedef struct Token Token;
typedef struct HashTableItem HashTableItem;
typedef struct HashTable HashTable;

struct Token {
    char* type;
    char* value;
};

struct HashTableItem {
    Token* token;
};

struct HashTable {
    // an array of pointers to HashTableItem
    HashTableItem** items;
    // TODO: DO NOT HARDCODE THE SIZE
    int size; // the max size of the HashTable
    int count; // How many items are currently on the list;
};

// create the Token, HashTableItem and HashTable
[[maybe_unused]] int HashFunction(char* type, char* value);
Token* createToken(char* type, char* value);
HashTableItem* createItem(Token* token);
HashTable* createTable(int size);

// HashTable algorithms
void HashTableInsert(HashTable* table, char* value, char* type);

#endif // RYTHON_TOKEN_HPP
