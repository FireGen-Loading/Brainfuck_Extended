#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>

char* readFilePtr(FILE* file) {
    long length;
        
    fseek (file, 0, SEEK_END);
    length = ftell(file);
    fseek (file, 0, SEEK_SET);
        
    char* buffer = malloc(length * sizeof(char) +1);
    fread (buffer, 1, length, file);
    buffer[length] = 0;
    return buffer;
}

void brainFuckExtra(char* codeSeg, char* dataSeg, int* stackSeg) {
    int codePointer = 0;
    int dataPointer  = 0;
    int stackPointer = -1;

    while (1) {
        char Cchar = codeSeg[codePointer];
        switch (Cchar) {
        case '>':
            dataPointer++;
            break;
        case '<':
            --dataPointer;
            break;
        case '+':
            dataSeg[dataPointer]++;
            break;
        case '-':
            dataSeg[dataPointer]--;
            break;
        case '[':
            stackPointer++;
            stackSeg[stackPointer] = codePointer;
            break;
        case ']':
            if (!dataSeg[dataPointer])
                --stackPointer;
            else codePointer = stackSeg[stackPointer];
            break;
        case '.':
            putchar(dataSeg[dataPointer]);
            break;
        case ',':
            char input = getchar();
            dataSeg[dataPointer] = input;
            break;
        case '?':
            *(int*)(dataSeg + dataPointer) = system(dataSeg+dataPointer);
            break;
        case '%':
            FILE* file = fopen((const char*)dataSeg+dataPointer, "r");
            char* buffer = readFilePtr(file);
            brainFuckExtra(buffer, dataSeg, stackSeg);
            fclose(file);
            free(buffer);
            break;
        case '\0':
            return;
            break;
        default:
            break;
        }
        codePointer++;
    }
    free(dataSeg);
    free(stackSeg);
}

int main(int argc, char** argv) {
    switch (argc) {
    case 1:
        printf("please supply a file path");
    case 2:
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            printf("please supply a valid file path\n");
            return -1;
        }

        char* buffer = readFilePtr(file);
        fclose (file);

        const int dataSegSize = 30000; // useless var 1
        const int stackSegSize = 100; // usless var 2

        char* dataSeg = calloc(dataSegSize, sizeof(char));
        int* stackSeg = calloc(stackSegSize, sizeof(int));

        brainFuckExtra(buffer, dataSeg, stackSeg);
        break;
    default:
        printf("Please only supply a file path\n");
        break;
    }
}