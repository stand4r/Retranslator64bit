#include <stdio.h>

void convertToBinary(FILE* input, FILE* output) {
    int byte;
    while ((byte = fgetc(input)) != EOF) {
        for (int i = 7; i >= 0; i--) {
            fprintf(output, "%d", (byte >> i) & 1);
        }
    }
}

int main() {
    FILE* inputFile = fopen("sublime_text.exe", "rb");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error in open file.");
        return 1;
    }

    convertToBinary(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Convertation complete.");

    return 0;
}