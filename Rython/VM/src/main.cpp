#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "../include/util.hpp"


int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Interactive interpreter is not available yet");
        return 1;
    }

    char* source = readFiles(argv[1]);
    printf("%s\n", source);
    free(source);

    return 0;
}
