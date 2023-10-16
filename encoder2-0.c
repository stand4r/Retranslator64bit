#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *inputFile = fopen("input.exe", "rb");
    if (inputFile == NULL) {
        printf("Не удалось открыть входной файл.\n");
        return 1;
    }

    FILE *binaryFile = fopen("output.bin", "wb");
    if (binaryFile == NULL) {
        printf("Не удалось создать выходной файл.\n");
        fclose(inputFile);
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, inputFile)) > 0) {
        fwrite(buffer, sizeof(unsigned char), bytesRead, binaryFile);
    }

    fclose(inputFile);
    fclose(binaryFile);

    FILE *outputFile = fopen("output.exe", "wb");
    if (outputFile == NULL) {
        printf("Не удалось создать файл для восстановления.\n");
        return 1;
    }

    binaryFile = fopen("output.bin", "rb");
    if (binaryFile == NULL) {
        printf("Не удалось открыть файл с бинарными данными.\n");
        fclose(outputFile);
        return 1;
    }

    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, binaryFile)) > 0) {
        fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
    }

    fclose(outputFile);
    fclose(binaryFile);

    return 0;
}