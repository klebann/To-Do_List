/* 00 system includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/* 01 project includes */
#include "task.h"
#include "timestamp.h"
#include "FileManager.h"

#define TITLESIZE 100
#define CONTENTSIZE 100
#define BUFFER_SIZE 300

struct Task{
    unsigned id;
    char *title;
    char *content;
    time_t creation;
    time_t begin;
    time_t end;
};

void addTask(){
    struct Task *task = getTaskFromUser();

    puts("\n============TASK============");
    showTask(task);

    if (confirmAdding()){
        saveTask(task);
    }
}

struct Task *initTask(){
    struct Task *task = (struct Task*) malloc(sizeof(struct Task));
    task->title = (char *) malloc(sizeof(char [TITLESIZE]));
    task->content = (char *) malloc(sizeof(char [CONTENTSIZE]));
    return task;
}

struct Task **initTaskList(int size){
    struct Task **tasks = (struct Task**) malloc(sizeof(struct Task*) * size);
    for (int i=0; i<size; i++){
        tasks[i] = initTask();
    }
    return tasks;
}

struct Task *getTaskFromUser(){
    struct Task *task = initTask();

    task->id = getNewId();
    task->creation = (int)time(NULL);
    getTitleFromUser(task->title);
    getContentFromUser(task->content);

    task->begin = getTimestampFromUser("Begin ");
    task->end = getTimestampFromUser("End ");

    return task;
}

int getNewId(){
    return getLastIdFromFile() + 1;
}

void getTitleFromUser(char *title){
    scanf("%*c"); //discard the newline (without it will be skipped)
    printf("Title: ");
    scanf("%[^\n]%*c", title); //whole line maybe fgets() on linux
}

void getContentFromUser(char *content){
    printf("Content: ");
    scanf("%[^\n]%*c", content);
}

bool confirmAdding(){
    printf("Do you want to save it(y/n): ");
    char answer[5];
    scanf("%s",answer);
    if (strcmp(answer, "y") == 0) {
        return true;
    }
    else {
        return false;
    }
}

void saveTask(struct Task *task){
    FILE *fp;
    fp = fopen("data/tasks.txt", "a+");
    fprintf(fp, "%d;%s;%s;%lld;%lld;%lld\n", task->id, task->title, task->content, (long long)task->creation, (long long)task->begin, (long long)task->end);
    fclose(fp);
}

void editTaskInFile(struct Task *task, int id){
    FILE * fPtr;
    FILE * fTemp;
    char path[] = "data/tasks.txt";
    char buffer[BUFFER_SIZE];

    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w");

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }


    /*
     * Read line from source file and write to destination
     * file after replacing given line.
     */
    int count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current id is line to replace */
        if (count == id)
            fprintf(fTemp, "%d;%s;%s;%lld;%lld;%lld\n", task->id, task->title, task->content, (long long)task->creation, (long long)task->begin, (long long)task->end );
        else
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("replace.tmp", path);
}

void showList(){
    int taskCount = getLastIdFromFile();
    struct Task **tasks = initTaskList(taskCount);

    if (taskCount <= 0){
        puts("There is no tasks");
        return;
    }

    getTasksFromFile(tasks);

    showAllTasks(tasks, taskCount);

    makePause();
}

void getTasksFromFile(struct Task **tasks){
    FILE *fp;
    char line[255];

    char filename[] = "data/tasks.txt";

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return;
    }

    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        tasks[i]->id = atoi(strtok(line, ";"));
        strcpy(tasks[i]->title, strtok(NULL, ";"));
        strcpy(tasks[i]->content, (char *)strtok(NULL, ";"));
        tasks[i]->creation = (time_t)atoll(strtok(NULL, ";"));
        tasks[i]->begin = (time_t)atoll(strtok(NULL, ";"));
        tasks[i]->end = (time_t)atoll(strtok(NULL, ";"));
        i++;
    }
    fclose(fp);

    return tasks;
}

void getTaskWithIdFromFile(struct Task *task, int id){
    FILE *fp;
    char line[255];

    char filename[] = "data/tasks.txt";

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return;
    }

    int i = 0;
    bool found = false;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if ((i + 1) == id) {
            task->id = atoi(strtok(line, ";"));
            strcpy(task->title, strtok(NULL, ";"));
            strcpy(task->content, (char *)strtok(NULL, ";"));
            task->creation = (time_t)atoll(strtok(NULL, ";"));
            task->begin = (time_t)atoll(strtok(NULL, ";"));
            task->end = (time_t)atoll(strtok(NULL, ";"));

            found = true;
        }
        i++;
    }
    fclose(fp);

    if (!found) {
        printf("Don't found any Task with id=%d in %s\n", id, filename);
    }
}

void showAllTasks(struct Task **tasks, int count){
    puts("\n============TASKS============");
    for (int i=0; i<count; i++){
        showTask(tasks[i]);
        puts("-----------------------------");
    }
    return;
}

void deleteTask(){

}

void editTask(){
    int id = getIdFromUser();
    int lastId = getLastIdFromFile();

    if (!isIdValid(id, lastId)) {
        printf("Enter ID in range 1-%d\n", lastId);
        return;
    }

    struct Task *task = initTask();

    getTaskWithIdFromFile(task, id);

    puts("============TASK============");
    showTask(task);
    puts("----------------------------");

    struct Task *newTask = getTaskFromUser();
    newTask->id = id;

    puts("==========NEW TASK==========");
    showTask(newTask);
    puts("----------------------------");

    if (confirmAdding()){
        editTaskInFile(newTask, id);
    }

    makePause();
}

int getIdFromUser(){
    int id = 0;
    printf("Task ID: ");
    scanf("%d", &id);
    return id;
}

bool isIdValid(int id, int lastId){
    if (id > 0 && id <= lastId){
        return true;
    }
    return false;
}

void showTask(struct Task *task){
    printf("ID:\t\t%d\n", task->id);
    printf("Title:\t\t%s\n", task->title);
    printf("Content:\t%s\n", task->content);
    printHumanReadableDate(task->creation, "Created at:\t");
    printHumanReadableDate(task->begin, "Starts at:\t");
    printHumanReadableDate(task->end, "Ends at:\t");
}

void showStatistics(){

}


