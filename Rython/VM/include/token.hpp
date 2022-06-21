#ifndef RYTHON_TOKEN_HPP
#define RYTHON_TOKEN_HPP
#include <cstring>
#include <sstream>
#include <vector>
#include <regex>
#include "../include/table.hpp"
#include "util.hpp"

struct Token {
    char* type;
    char* value;
};


unsigned int HashFunction(char* str);

typedef struct HashTableItem HashTableItem;
typedef struct HashTable HashTable;

// define the hash table item
struct HashTableItem {
    char* key;
    char* value;
};

// define the hash table
struct HashTable {
    // contains an array of pointers to items
    HashTableItem** items;
     int size; // max size of the table
     int count; // how many items are in the HashTable
};

Token* createToken(char* type, char* value);
HashTable* Tokenize(char* lineBuf);


// create the hashtable and it's items
HashTableItem* createItem(Token* Token);
HashTable* createTable(int size);

// memory management
void freeItem(HashTableItem* item);
void freeTable(HashTable* table);

// hash table algorithms
void HashTableInsert(HashTable* table, Token* token);
char* HashTableSearch(HashTable* table, char* key);
void HashTableDelete(HashTable* table, char* key);

// testing
void printSearch(HashTable* table, char* key);
void printTable(HashTable* table);

#endif // RYTHON_TOKEN_HPP
