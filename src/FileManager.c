/* 00 system includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 01 project includes */
#include "FileManager.h"

int getLastIdFromFile(){
    FILE *fp;
    char line[255];
    int lastId = 0;

    fp = fopen("data/tasks.txt", "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        lastId = atoi(strtok(line, ";"));
    }
    fclose(fp);

    return lastId;
}
