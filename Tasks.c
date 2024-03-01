#include"Functions.h"
#include"FileOutputFunctions.h"
#include"FileFillingFunctions.h"

void TaskOne(char*FilePath){
    TaskOneInput(FilePath);
    PrintMin(TaskOneFunc(FilePath));
}

void TaskTwo(char*FilePath){
    TaskTwoInput(FilePath);
    PrintResult(TaskTwoFunc(FilePath), FilePath);
}

void TaskThree(char*FilePath){
    PrintResult(TaskThreeFunc(FilePath, TaskThreeInput(FilePath)), FilePath);
}
