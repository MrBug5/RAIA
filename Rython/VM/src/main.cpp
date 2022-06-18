#include <cstdlib>
#include <cstdio>

#include "../include/util.hpp"
#include "../include/token.hpp"
#include "../include/table.hpp"

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Interactive Interpreter is not available yet.\n");
        return 3;
    }

    char* source = readFiles(argv[1]);
    printf("%s\n", source);


    // free(tokens)
    free(source);

    return 0;
}
