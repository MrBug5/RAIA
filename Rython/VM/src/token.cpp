#include "../include/token.hpp"
#include "../include/util.hpp"

int HashFunction(char* type, char* value) {
    char* buffer = new char[strlen(type) + strlen(value) + 1 + 1];
    strcpy(buffer, type);
    strcat(buffer, value);

    int i = 0;
    for(int j=0;buffer[j];j++)
        i += buffer[j];

    return i % 50000;
}

Token* createToken(char* type, char* value) {
    // allocate memory for the token
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = (char*) malloc(strlen(type) + 1);
    token->value = (char*) malloc(strlen(value) + 1);

    strcpy(token->type, type);
    strcpy(token->value, value);

    return token;
}


HashTableItem* createItem(Token* token) {
    // allocate memory for the item
    HashTableItem* item = (HashTableItem*) malloc(sizeof(HashTableItem));
    item->token = (Token*) malloc(sizeof(Token));
    item->token = token;

    return item;
}

HashTable* createTable(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->count = 0;
    table->size = size;
    table->items = (HashTableItem**) calloc(table->size, sizeof(HashTableItem*));

    for (int i=0;i<table->size;i++)
        table->items[i] = NULL;

    return table;
}


void freeToken(Token* token) {
    free(token->type);
    free(token->value);
    free(token);
}


void freeItem(HashTableItem* item) {
    freeToken(item->token);
    free(item);
}

void freeTable(HashTable* table) {
    for (int i=0;i<table->size;i++) {
        if (table->items[i] != NULL)
            freeItem(table->items[i]);
    }
    free(table->items);
    free(table);
}


void HashTableInsert(HashTable* table, char* type, char* value) {
    Token* token = createToken(type, value);
    HashTableItem* item = createItem(token);
    // compute the index
    int index = HashFunction(type, value);
    HashTableItem* currentItem = table->items[index];

    if (currentItem == NULL) {
        // item does not exist
        if (table->count == table->size) {
            printf("Insert Error: Table is full\n");
            freeItem(item);
            return;
        }

        // insert directly
        table->items[index] = item;
        table->count++;
    }
}

void printTable(HashTable* table) {
    printf("\n--------------------------------Hash Table--------------------------------\n");
    for (int i=0;i<table->size;i++) {
        if(table->items[i]) {
            printf("Type: %s\t\t\tValue: %s\n", table->items[i]->token->type, table->items[i]->token->value);
        }
    }
    printf("--------------------------------------------------------------------------\n");
}

HashTable* Tokenize(char* lineBuffer) {
    HashTable* __xLT__ = createTable(50000);
    std::vector<__xxTPT07__> __VTM__AS__ = {__xxTPT07__::IDENTIFIER, __xxTPT07__::OPERATOR, __xxTPT07__::LITERAL};
    std::vector<__xxTPT07__> __FRM_BF__ = Iden(lineBuffer);
    if (__FRM_BF__ == __VTM__AS__) {
        std::smatch m1;
        std::smatch m4;
        std::regex __xxTPT01__("\\w+\\s*(?==)");
        std::regex __xxTPT04__("=(?=\\s*'|\\w)");

        std::string __llBB__(lineBuffer);
        char* IDE;
        char* OPE;
        char* LIT;
        if (std::regex_search(__llBB__, m1, __xxTPT01__)) {
            std::string __lm(m1.str(0));
            IDE = (char*) __lm.c_str();
            HashTableInsert(__xLT__, "identifier", IDE);
        }
        if (std::regex_search(__llBB__, m4, __xxTPT04__)) {
            std::string __ldm(m4.str(0));
            OPE = (char*) __ldm.c_str();
            HashTableInsert(__xLT__, "operator", OPE);
        }

        // TODO: this is not neat. come clean this up later.
        std::string __STRLIT = __llBB__.substr(__llBB__.find("=") + 1);
        LIT = (char*)__STRLIT.c_str();
        if (LIT)
            HashTableInsert(__xLT__, "literal", LIT);
    }
    return __xLT__;
}
