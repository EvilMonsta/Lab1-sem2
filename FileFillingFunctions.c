#include<stdlib.h>
#include<stdio.h>
#include"Functions.h"
#include<time.h>
void HandFileFilling(int length, char*FilePath)
{
    FILE *bfile = checkFileOpener(FilePath);
    int value = 0;
    bfile =  fopen(FilePath,"rb+");
    for (int i = 0; i < length; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        fwrite(&value, sizeof(int), 1, bfile);
    }
    fclose(bfile);
}

void EmptyFileFilling(int length, char*FilePath){
    int voidnumber = 0;
    FILE *bfile = checkFileOpener(FilePath);
    bfile =  fopen(FilePath,"wb+");
    for (int i = 0; i < length; i++) {
        fwrite(&voidnumber, sizeof(int), 1, bfile);
    }
    fclose(bfile);
}

void RandomFileFilling(int length, char*FilePath) {
    int randomNumber;

    FILE *bfile = checkFileOpener(FilePath);
    bfile =  fopen(FilePath,"rb+");

    for (int i = 0; i < length; i++) {
        srand(time(NULL) * (i + rand() % 100));
        randomNumber = rand() % 100;
        fwrite(&randomNumber, sizeof(int), 1, bfile);
        printf("%d ", randomNumber);

    }
    fclose(bfile);
}

void ModRandomFileFilling(int length, char*FilePath) {
    int randomNumber;

    FILE *bfile = checkFileOpener(FilePath);
    bfile =  fopen(FilePath,"rb+");

    for (int i = 0; i < length; i++) {
        srand(time(NULL) * (i + rand() % 200));
        randomNumber = rand() % 200 - 100;
        fwrite(&randomNumber, sizeof(int), 1, bfile);
        printf("%d ", randomNumber);

    }
    fclose(bfile);
}
