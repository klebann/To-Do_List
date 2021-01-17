#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <stdbool.h>

/* Task structure containing all needed variables */
struct Task;

/* Add task from user input */
void addTask();

/* Ask user for title and save to variable */
void getTitleFromUser(char *title);

/* Ask user for content and save to variable */
void getContentFromUser(char *content);

/* Ask user for all component of task and return it */
struct Task *getTaskFromUser();

/* Show list of tasks */
void showList();

/* Delete task with id from parametr */
void deleteTask();

/* Edit task with id from parametr */
void editTask();

/* Show one task */
void showTask(struct Task *task);

/* Shows whole menu */
void showStatistics();

bool confirmAdding();

#endif
