#ifndef RYTHON_TABLE_HPP
#define RYTHON_TABLE_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
// #define CAPACITY 50000
#include "../include/token.hpp"


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


#endif // RYTHON_TABLE_HPP
