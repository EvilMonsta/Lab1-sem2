#include <stdio.h>
#include"Functions.h"
#include"FileFillingFunctions.h"
#include"FileOutputFunctions.h"
#include "Tasks.h"

int main(int argc, char**argv) {
    char *FilePath = argv[1];
    int tasknumber;
    do{
        printf("\nEnter task number[1,2,3] or [0] to exit the program: ");
        scanf("%d",&tasknumber);
        tasknumber = TaskNumCheck(tasknumber);
        if(tasknumber==1)
            TaskOne(FilePath);
        else if(tasknumber == 2)
            TaskTwo(FilePath);
        else if(tasknumber == 3)
            TaskThree(FilePath);
        tasknumber = ContinueWish(tasknumber);
        }
    while(tasknumber!=0);
    return 0;
}