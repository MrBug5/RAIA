#include "../include/token.hpp"
#include "../include/table.hpp"

Token* createToken(char* type, char* value) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = (char*) malloc(strlen(type) + 1);
    token->value = (char*) malloc(strlen(value) + 1);

    strcpy(token->type, type);
    strcpy(token->value, value);

    return token;
}

HashTable* Tokenize(char* lineBuf){
    std::vector<__xxTPT07__> __vbt__AS__ = {__xxTPT07__::IDENTIFIER, __xxTPT07__::OPERATOR, __xxTPT07__::LITERAL};
    std::vector<__xxTPT07__> __ID__AS__ = Iden(char* lineBuf);
    HashTable* Tokens = createTable(50000); // TODO: DO NOT HARDCODE TABLE->SIZE

    if (__ID__AS__ == __vbt__AS__) {
        // first things first, use regex to get the identifier in the line
        std::regex rgx("\\w*(?= =)")
        std::smatch m;
        std::string __sLB(lineBuf);
        if (std::regex_search(__sLB, m, rgx)) {
            std::string __sm(m.str(0));
            char* __csm = (char*)__sm.c_str();
            Token* __iden__ = createToken("1", __csm); /* TODO: DO NOT HARCODE TPYE */
            HashTableInsert(Tokens, __iden__);
        }
    }

    return Tokens;
}

#include "../include/table.hpp"


unsigned int HashFunction(char* str)  {
    int i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}


HashTableItem* createItem(Token* token) {
    // creates a pointer to a new hash table item
    HashTableItem* item = (HashTableItem*) malloc(sizeof(HashTableItem));
    item->key = (char*) malloc(strlen(token->type) + 1);
    item->value = (char*) malloc(strlen(token->value) + 1);

    strcpy(item->key, token->type);
    strcpy(item->value, token->value);

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

void HashTableInsert(HashTable* table, Token* token) {
    // create the item
    HashTableItem* item = createItem(token->key, token->value);

    // compute the index
    [[maybe_unused]] int index = HashFunction(token->key);

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
