#ifndef RYTHON_TOKEN_HPP
#define RYTHON_TOKEN_HPP
#include <cstring>
#include <sstream>
#include <vector>
#include <regex>
#include "../include/table.hpp"
#include "../include/util.hpp"

struct Token {
    char* type;
    char* value;
};

Token* createToken(char* type, char* value);
HashTable* Tokenize(char* lineBuf);

#endif // RYTHON_TOKEN_HPP
