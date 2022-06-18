#ifndef RYTHON_TABLE_HPP
#define RYTHON_TABLE_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define CAPACITY 50000

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

// create the hashtable and it's items
HashTableItem* createItem(char* key, char* value);
HashTable* createTable(int size);

// memory management
void freeItem(HashTableItem* item);
void freeTable(HashTable* table);

// hash table algorithms
void HashTableInsert(HashTable* table, char* key, char* value);
char* HashTableSearch(HashTable* table, char* key);
void HashTableDelete(HashTable* table, char* key);

// testing
void printSearch(HashTable* table, char* key);
void printTable(HashTable* table);


#endif // RYTHON_TABLE_HPP
