#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"FileFillingFunctions.h"
#include"FileOutputFunctions.h"
#include<time.h>


int FileFillingChoice(){
    printf("\nIf u want to use your own elements than enter [1], else [0] : ");
    int choice;
    scanf("%d",&choice);
    if(choice == 1 )   return 1;
    else if(choice == 0) return 0;
    else {
        printf("ERROR");
        exit(-1);
    }
}

void* checkFileOpener(char* filePath) {
    FILE* file = NULL;
    file = fopen(filePath, "rb");

    if (file == NULL) {
        printf("\n\tfailed access to the file\n");
        exit(-1);
    }
return file;
}

int TaskNumCheck(int tasknum){
    if(tasknum > 3 || tasknum < 0){
        printf ("ERROR");
        return 0;
    }
    return tasknum;
}

void Swap(int firstvalue,int secondvalue, int pos, char*FilePath){
    FILE *bfile = NULL;
    bfile =  fopen(FilePath,"rb+");
    fseek(bfile, pos*sizeof(int), SEEK_SET);
    fread(&firstvalue, sizeof(int), 1, bfile);
    fread(&secondvalue, sizeof(int), 1, bfile);
    int tmp;
    tmp = firstvalue;
    firstvalue = secondvalue;
    secondvalue = tmp;
    fseek(bfile, pos*sizeof(int), SEEK_SET);
    fwrite(&firstvalue, sizeof(int), 1, bfile);
    fwrite(&secondvalue, sizeof(int), 1, bfile);
    fclose(bfile);
}


void BubbleSort(int size,char*FilePath,int t){
    FILE *bfile = NULL;
    bfile =  fopen(FilePath,"rb+");
    int swapfinder = 0,firstvalue,secondvalue;
    for(int i = size - 1; i >= t; i--) {
        swapfinder = 1;
        for(int j = t; j < i; j++) {
            fseek(bfile, j*sizeof(int), SEEK_SET);
            fread(&firstvalue, sizeof(int), 1, bfile);
            fread(&secondvalue, sizeof(int), 1, bfile);
            if(firstvalue > secondvalue)
            {
                Swap(firstvalue,secondvalue,j,FilePath);
                swapfinder = 1;
            }
            swapfinder = 1;
            rewind(bfile);
        }
    }
    fclose(bfile);
}

void CheckElementK(int k){
    if(k<=0){
        printf("ERROR");
        (exit-1);
    }
}

int GetLength(char*FilePath){
    int counter;
    FILE *bfile=fopen(FilePath, "rb");
   fseek(bfile,0,SEEK_END);
   counter = ftell(bfile)/4;
   return counter;
}

int LengthChoice(char* FilePath){
    int length = 0, lengthchoice = 0;
    printf("\nEnter 1 to write amount of elements\nEnter 2 to use random(5-20) amount of elements\nEnter 0 to exit\n");
    scanf("%d",&lengthchoice);
    if(lengthchoice == 2){
        srand(time(NULL) * (5 + rand() % 15));
        length = 5 + rand()%15;
        printf("\nYour amount of elements in file is: %d", length);
    }
    else if(lengthchoice == 1){
        printf("\nEnter amount of elements in file: ");
        scanf("%d",&length);
    }
    else exit(-1);
    EmptyFileFilling(length, FilePath);
    return length;
}

int ContinueWish(int tasknumber){
    int wish = tasknumber;
    if(tasknumber==0){
        return wish;
    }
    printf("\nWant to continue work with program?\n1 - Yes\n0 - No\nYour choice: ");
    scanf("%d",&wish);
    if(wish<0 || wish > 1){
         printf("ERROR");
         return 0;
    }
    return wish;
}

int TaskOneFunc(char*FilePath){
    FILE *bfile = NULL;
    bfile =  fopen(FilePath,"rb");
    int pos=1, value, MinValuePosition = 0, PreElement = 0, Multiplex = INT_MAX, length = GetLength(FilePath);
    fread(&value, sizeof(int),1,bfile);
    PreElement = value;
    for (int i = 1; i < length; i++,pos++) {
        fread(&value, sizeof(int), 1, bfile);
        if(value*PreElement<Multiplex){
            Multiplex = value*PreElement;
            MinValuePosition = pos;
        }
    }
    fclose(bfile);
    return MinValuePosition;
}

int TaskTwoFunc(char*FilePath){
    int pos = 0, value, ANTIvalue,length = GetLength(FilePath);;
    FILE *bfile = NULL;
    bfile =  fopen(FilePath,"rb+");
    for (int i = 0; i < length; i++,pos++) {
        fseek(bfile, pos*sizeof(int), SEEK_SET);
        fread(&value, sizeof(int), 1, bfile);
        ANTIvalue = value * (-1);
        fseek(bfile, pos*sizeof(int), SEEK_SET);
        fwrite(&ANTIvalue, sizeof(int), 1, bfile);
    }
    fclose(bfile);
    return length;
}

int TaskThreeFunc(char*FilePath, int k){
    int curlength, size, curpos, length = GetLength(FilePath);
    FILE *bfile = NULL;
    bfile =  fopen(FilePath,"rb+");
    CheckElementK(k);
    curpos = length - length % k;
    curlength = curpos;
    size = length;
    for(int i = 0; i <= curlength / k; i++){
        BubbleSort(size,FilePath,curpos);
        size = curpos;
        curpos = curpos - k;
    }
    fclose(bfile);
    return length;
}

void TaskOneInput(char*FilePath){
    int choice, length = LengthChoice(FilePath);
    choice = FileFillingChoice();
    if(choice)  HandFileFilling(length,FilePath);
    else if(choice==0) {
        printf("\nYour original file elements yo:\n");
        RandomFileFilling(length,FilePath);
    }
}

int TaskThreeInput(char*FilePath){
    int choice, length = LengthChoice(FilePath), k;
    choice = FileFillingChoice();
    if(choice) HandFileFilling(length,FilePath);
    else if(choice==0){
        printf("\nYour original file elements:\n");
        ModRandomFileFilling(length,FilePath);
    }
    printf("\nEnter [k]:\n");
    scanf("%d",&k);
    return k;
}

void TaskTwoInput(char*FilePath){
    int choice, length = LengthChoice(FilePath);
    choice = FileFillingChoice();
    if(choice) HandFileFilling(length,FilePath);
    else if(choice==0){
        printf("\nYour original file elements:\n");
        ModRandomFileFilling(length,FilePath);
    }
}
