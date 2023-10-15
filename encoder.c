#include <stdlib.h>
#include <stdio.h>
int main () {
    int bufer; 
    int chotchik; 
 
    FILE *f;
    FILE *f1;
    f= fopen ("sublime_text.exe","rb");  
    
    //Теперь откроем файл результат
    f1= fopen ("rez.txt","w");
    if (!f1) {
        return -2;
    } 
        do {
        bufer= fgetc (f);
        if (bufer!=EOF) {
            fprintf (f1, "%-0.2x%c", bufer, ' ');
        }
        chotchik++;
        if (!(chotchik%16)) fputc (10, f1);
        } while (bufer!= EOF);
        fseek (f1, 1, SEEK_CUR);
        fscanf (f1, "%x", &bufer);
        fclose (f1);
    
    //Разберёмся с закрытием файлов
    if (f) {
        fclose (f);
    }
    return 0;
}