#ifndef RYTHON_TOKEN_HPP
#define RYTHON_TOKEN_HPP
#include <cstring>
#include <cstdlib>
#include <cstdio>

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
int HashFunction(char* type, char* value);
Token* createToken(char* type, char* value);
HashTableItem* createItem(Token* token);
HashTable* createTable(int size);

// HashTable algorithms
void HashTableInsert(HashTable* table, char* type, char* value);
char* HashTableSearch(HashTable* table, char* type);
void printTable(HashTable* table);


// memory management
void freeToken(Token* token);
void freeItem(HashTableItem* item);
void freeTable(HashTable* table);
#endif // RYTHON_TOKEN_HPP
