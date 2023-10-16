#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("proj1.exe", "r");
    FILE *file2 = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Не удалось открыть файл");
        return 1;
    }
    if (file2 == NULL) {
        printf("Не удалось открыть файл");
        return 1;
    }

    // Определение размера файла
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Выделение памяти под буфер
    char *buffer = (char*)malloc(file_size * sizeof(char));

    // Чтение байтов файла
    fread(buffer, sizeof(char), file_size, file);

    // Закрытие файла
    fclose(file);

    // Вывод представления файла в виде 0 и 1
    for (int i = 0; i < file_size; i++) {
            int byte = buffer[i];
            fwrite(&byte, sizeof(byte), sizeof(byte), file2);
    }
    fclose(file2);
    free(buffer);

    return 0;
}