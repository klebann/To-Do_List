/* 00 system includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/* 01 project includes */
#include "task.h"
#include "timestamp.h"

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
    showTask(task);
    if (confirmAdding()){
        puts("Saving to file...");
    }
}

struct Task *getTaskFromUser(){
    struct Task *task = (struct Task*) malloc(sizeof(struct Task));
    task->title = (char *) malloc(sizeof(char [TITLESIZE]));
    task->content = (char *) malloc(sizeof(char [CONTENTSIZE]));

    task->id = 1; //TODO: from database
    task->creation = (int)time(NULL);
    getTitleFromUser(task->title);
    getContentFromUser(task->content);

    task->begin = getTimestampFromUser("Begin ");
    task->end = getTimestampFromUser("End ");

    return task;
}

void getTitleFromUser(char *title){

    printf("Title: ");
    scanf("%s", title);
}

void getContentFromUser(char *content){
    printf("Content: ");
    scanf("%s", content);
}

void showList(){

}

void deleteTask(){

}

void editTask(){

}

void showTask(struct Task *task){
    puts("\n------------TASK------------");
    printf("ID:\t\t%d\n", task->id);
    printf("Title:\t\t%s\n", task->title);
    printf("Content:\t%s\n", task->content);
    printHumanReadableDate(task->creation, "Created at:\t");
    printHumanReadableDate(task->begin, "Starts at:\t");
    printHumanReadableDate(task->end, "Ends at:\t");
}

void showStatistics(){

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
