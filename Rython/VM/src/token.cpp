#include "../include/token.hpp"

int HashFunction(char* value) {
    int i = 0;
    char* str
    for (int j=0;value[j];j++)
        i += str[j];

    return i % 5000000;
}

Token* createToken(char* type, char* value) {
    // memory allocate space for the Token
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = (char*) malloc(strlen(type) + 1);
    token->value = (char*) malloc(strlen(value) + 1);

    strcpy(token->type, type);
    strcpy(token->value, value);

    return token;
}


HashTableItem* createItem(Token* token) {
    HashTableItem* item = (HashTableItem*) malloc(sizeof(HashTableItem));
    item->token = (Token*) malloc(sizeof(Token));
    item->token = token;

    return item;
}

HashTable* createTable(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    int size = size;
    int count = 0;
    HashTableItem** items = (HashTableItem**) calloc(table->size, sizeof(HashTableItem*));

    for (int i=0;i<table->size;i++)
        table->items[i] = NULL;

    return table;
}

void HashTableInsert(HashTable* table, char* value, char* type) {
    Token* token = createToken(type, value);
    HashTableItem item = createItem(token);

    if (table->size == table->count) {
        printf("Insert Error: Table is full\n");
        return;
    }

    // insert directly
    int index =

}
