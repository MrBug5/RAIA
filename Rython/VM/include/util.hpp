#ifndef RYTHON_UTIL_HPP
#define RYTHON_UTIL_HPP
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <regex>
#include <sstream>
#include <type_traits>

enum __xxTPT07__ {
    IDENTIFIER = 1,  // x, number, name, age, etc
    KEYWORD,  // print, if, input, return
    SEPARATOR, // }, |,
    OPERATOR, // >, +, -, =, /, //
    LITERAL,  // 10, "Jason", True
    COMMENT, // # this is a comment.
};

std::vector<std::string> kwlist = {"print", "False", "None", "True",
                                    "__peg_parser__", "and", "as", "assert",
                                    "async", "await", "break", "class",
                                    "continue", "def", "del",
                                    "elif", "else", "except", "finally",
                                    "for", "from", "global", "if", "import",
                                    "in", "is", "lambda", "nonlocal",
                                    "not", "or", "pass", "raise", "return",
                                    "try", "while", "with", "yield"};

char* readFiles(char* path);
std::ostream& operator << (std::ostream& os, const __xxTPT07__& obj);
std::vector<__xxTPT07__> Iden(char* lineBuf);
char* intToChar(int a);

#endif // RYTHON_UTIL_HPP
