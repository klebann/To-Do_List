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
    char filename[] = "data/tasks.txt";

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Nothing in %s\n", filename);
        return 0;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        lastId = atoi(strtok(line, ";"));
    }
    fclose(fp);

    return lastId;
}
