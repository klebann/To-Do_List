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

/* get new unique Id for task (based on last ID)*/
int getNewId();

/* ask user if he confirm data and if "y" then save task */
bool confirmAdding();

/* save task to file */
void saveTask(struct Task *task);

/* Show list of tasks */
void showList();

/* Returns list of tasks form file */
void getTasksFromFile(struct Task *tasks);

/* shows all tasks from task list */
void showAllTasks(struct Task *tasks, int count);

/* Delete task with id from parameter */
void deleteTask();

/* Edit task with id from parameter */
void editTask();

/* Show one task */
void showTask(struct Task *task);

/* Shows whole menu */
void showStatistics();

#endif
