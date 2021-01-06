/* 00 system includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 01 project includes */
#include "task.h"
#include "timestamp.h"

struct Task{
    unsigned id;
    time_t creation;
    time_t begin;
    time_t end;
    char *title;
    char *content;
};

void addTask(){
    struct Task task = getTaskFromUser();

}

struct Task getTaskFromUser(){
    struct Task task;
    task.creation = (int)time(NULL);
    task.title = getTitleFromUser();
    task.content = getContentFromUser();

    task.begin = getTimestampFromUser();
}

const char* getTitleFromUser(){
    printf("Title: ");
    char *title;
    scanf("%s", title);
    return title;
}

const char* getContentFromUser(){
    printf("Content: ");
    char *content;
    scanf("%s", content);
    return content;
}

void showList(){

}

void deleteTask(){

}

void editTask(){

}

void showStatistics(){

}
