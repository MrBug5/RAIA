  #include "../include/parser.hpp"
  #include "../include/util.hpp"

 void ParserStart(TokenList* list, char* source) {
     char lex[256];
     int lexi = 0;
     int i = 0;

     while (source[i] != ' ' && source[i] != '\n' && source[i] != '\0') {
         lex[lexi++];
     }
}
