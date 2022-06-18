#include "../include/token.hpp"

Token* createToken(char* type, char* value) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = (char*) malloc(strlen(type) + 1);
    token->value = (char*) malloc(strlen(value) + 1);

    strcpy(token->type, type);
    strcpy(token->value, value);

    return token;
}

HashTable* Tokenize(char* lineBuf) {
    /* START HERE */
    std::vector<__xxTPT06__> __vtm_As__ = { __xxTPT06__::IDENTIFIER,
                                            __xxTPT06__::OPERATOR,
                                            __xxTPT06__::LITERAL};
    /* END HERE */

    HashTable* __TT00__ = createTable(50000); // TODO: DO NOT HARDCODE SIZE
    // std::vector<char*> tokens;
    std::vector<__xxTPT06__> __IDS__ = Iden(lineBuf);
    if (__IDS__ == __vtm_As__) {
        std::regex rgx("\\w+");
        std::smatch m;
        std::string __STT__(lineBuf);
        if (std::regex_search(__STT__, m, rgx)) {
            std::string m__val__(m.str(0));
            char* _fou__ = (char*)m__val__.c_str();
            char* __ITC__ =  intToChar(__xxTPT06__::IDENTIFIER);
            HashTableInsert(__TT00__, "1", _fou__);
        }
    return __TT00__;
    }
}
