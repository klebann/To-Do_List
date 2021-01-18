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

struct Task *getTaskFromUser(){
    struct Task *task = (struct Task*) malloc(sizeof(struct Task));
    task->title = (char *) malloc(sizeof(char [TITLESIZE]));
    task->content = (char *) malloc(sizeof(char [CONTENTSIZE]));

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

void showList(){
    int taskCount = getLastIdFromFile();
    struct Task *tasks = (struct Task*) malloc(sizeof(struct Task) * taskCount);
    for (int i=0; i<taskCount; i++){
        tasks[i].title = (char *) malloc(sizeof(char [TITLESIZE]));
        tasks[i].content = (char *) malloc(sizeof(char [CONTENTSIZE]));
    }

    if (taskCount <= 0){
        puts("There is no tasks");
        return;
    }

    getTasksFromFile(tasks);

    showAllTasks(tasks, taskCount);
    system("pause"); //WINDOWS...
}

void getTasksFromFile(struct Task *tasks){
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
        tasks[i].id = atoi(strtok(line, ";"));
        strcpy(tasks[i].title, strtok(NULL, ";"));
        strcpy(tasks[i].content, (char *)strtok(NULL, ";"));
        tasks[i].creation = (time_t)atoll(strtok(NULL, ";"));
        tasks[i].begin = (time_t)atoll(strtok(NULL, ";"));
        tasks[i].end = (time_t)atoll(strtok(NULL, ";"));
        i++;
    }
    fclose(fp);

    return tasks;
}

void showAllTasks(struct Task *tasks, int count){
    puts("\n============TASKS============");
    for (int i=0; i<count; i++){
        showTask(&tasks[i]);
        puts("-----------------------------");
    }
    return;
}

void deleteTask(){

}

void editTask(){

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


