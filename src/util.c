#include "../include/util.h"



char* readAsciiFile(const char* path) 
{
    // Create a readonly file
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Couldn't open file '%s'\n", path);
        return NULL; // TODO Replace, we do not want any null
    }

    // Read the file & close it
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buf = (char*) malloc(sizeof(char) * (size + 1)); 
    if (!buf) {
        printf("Could not allocated memory for file!\n");
        return NULL; // Replace with something else
    }

    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);

    // Return the contents
    return buf;
}