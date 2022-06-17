#ifndef RYTHON_UTIL_HPP
#define RYTHON_UTIL_HPP
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <regex>
#include <sstream>
#include <type_traits>

enum __xxTPT06__ {
    IDENTIFIER = 1,  // x, number, name, age, etc
    KEYWORD,  // print, if, input, return
    SEPARATOR, // }, |,
    OPERATOR, // >, +, -, =, /, //
    LITERAL,  // 10, "Jason", True
    COMMENT, // # this is a comment.
};

char* readFiles(char* path);
std::ostream& operator << (std::ostream& os, const __xxTPT06__& obj);
std::vector<__xxTPT06__> Iden(char* lineBuf);
char* intToChar(int a);

#endif // RYTHON_UTIL_HPP
