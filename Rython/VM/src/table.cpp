#include "../include/table.hpp"


unsigned int HashFunction(char* str)  {
    int i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}


HashTableItem* createItem(char* key, char* value) {
    // creates a pointer to a new hash table item
    HashTableItem* item = (HashTableItem*) malloc(sizeof(HashTableItem));
    item->key = (char*) malloc(strlen(key) + 1);
    item->value = (char*) malloc(strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* createTable(int size) {
    // creates a pointer to a new hash table
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (HashTableItem**) calloc(table->size, sizeof(HashTableItem*));

    for (int i = 0;i<table->size;i++)
        table->items[i] = NULL;

    return table;
}

void freeItem(HashTableItem* item) {
    // frees an item
    free(item->key);
    free(item->value);
    free(item);
}

void freeTable(HashTable* table) {
    // frees the table
    for (int i=0;i<table->size;i++) {
        HashTableItem* item = table->items[i];
        if (item != NULL)
            freeItem(item);
    }
    free(table->items);
    free(table);
}

void HashTableInsert(HashTable* table, char* key, char* value) {
    // create the item
    HashTableItem* item = createItem(key, value);

    // compute the index
    [[maybe_unused]] int index = HashFunction(key);

    HashTableItem* currentItem = table->items[index];
    if (currentItem == NULL) {
        // key does not exist
        if (table->count == table->size) {
            // table is full
            printf("Insert Error: Hash Table is full\n");
            freeItem(item);
            return;
        }

        // insert directly
        table->items[index] = item;
        table->count++;
    }
}

char* HashTableSearch(HashTable* table, char* key) {
    // search the key in the hash table
    // and return null if it was not found
    int index = HashFunction(key);
    HashTableItem* item = table->items[index];

    // ensure that we move to a non NULL item
    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}

void printSearch(HashTable* table, char* key) {
    char* value;
    if ((value = HashTableSearch(table, key)) == NULL) {
        printf("Key: %s does not exist\n", key);
        return;
    } else {
        printf("Key: %s, Value: %s\n", key, value);
    }
}


void printTable(HashTable* table) {
    for (int i=0;i<table->size;i++) {
        if (table->items[i]) {
            printf("Key: %s, Value: %s\n", table->items[i]->key, table->items[i]->value);
        }
    }
}
