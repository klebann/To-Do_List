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
    getTitleFromUser(task.title);
    getContentFromUser(task.content);

    task.begin = getTimestampFromUser();
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

void showStatistics(){

}
