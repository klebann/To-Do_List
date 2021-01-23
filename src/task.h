#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <stdbool.h>

/* Task structure containing all needed variables */
struct Task;

/* Add task from user input */
void addTask();

/* Create new Task and correctly allocate memory */
struct Task *initTask();

/* Create new tasks list and correctly allocate memory */
struct Task **initTaskList(int size);

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

/* ask user if he confirm showed task to be deleteed by typing "y" */
bool confirmDeleting();

/* save task to file */
void saveTask(struct Task *task);

/* Edit task in file at id possition */
void editTaskInFile(struct Task *task, int id);

/* Show list of tasks */
void showList();

/* Returns list of tasks from file */
void getTasksFromFile(struct Task **tasks);

/* Returns one task from file */
void getTaskWithIdFromFile(struct Task *task, int id);

/* shows all tasks from task list */
void showAllTasks(struct Task **tasks, int count);

/* Delete task with id from parameter */
void deleteTask();

/* Edit task with id from parameter */
void editTask();

/* Ask user for id and returns */
int getIdFromUser();

/* Checks if given id is a valid id */
bool isIdValid(int id, int lastId);

/* Show one task */
void showTask(struct Task *task);

/* Shows whole menu */
void showStatistics();

#endif
