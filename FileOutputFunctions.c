#include<stdlib.h>
#include<stdio.h>
#include"Functions.h"

void PrintResult(int length, char* FilePath){
    FILE *bfile = NULL;
    bfile = checkFileOpener(FilePath);
    bfile =  fopen(FilePath,"rb");
    int pos=0, value;
    printf("\nYour result:\n");
    for (int i = 0; i < length; i++) {
        fseek(bfile, pos*sizeof(int), SEEK_SET);
        fread(&value, sizeof(int), 1, bfile);
        printf("%d ", value);
        rewind(bfile);
        pos++;
    }

    fclose(bfile);
}

void PrintMin(int MinElementPosition){
    printf("\nPosition of element, whose multiplex is minimal:  %d\n",MinElementPosition);
}