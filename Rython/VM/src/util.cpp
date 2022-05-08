#include "../include/util.hpp"

char* readFiles(const char* path) {
    // create the file object
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Could not open file: %s\n", path);
        return NULL;
    }

    // get file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // read file
    char* buf = (char*) malloc(sizeof(char) * (size));
    if (!buf) {
        printf("Could not allocate memory for file\n");
        return NULL;
    }
    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);

    // return buffer
    return buf;
}
