#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>

#include "../include/util.hpp"
#include "../include/token.hpp"
#include "../include/table.hpp"
#include "../include/openstack.hpp"

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Interactive Interpreter is not available yet.\n");
        return 3;
    }

    char* source = readFiles(argv[1]);
    char buffer[strlen(source) + 1];
    strcpy(buffer, source)
    char* temp = strtok(line, "\n");
    std::vector<char*> lines;
    while (temp != NULL) {
        lines.push_back(temp);
        temp = strtok(NULL, "\n");
    }

    // tokenize the first line and add it to the stack
    HashTable* first = Tokenize(lines[0]);
    Stack* MainStack = createStack(first);


    freeStack(MainStack);
    free(source);

    return 0;
}
