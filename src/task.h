#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

/* Task structure containing all needed variables */
struct Task;

/* Shows whole menu */
void addTask();

void getTitleFromUser(char *title);

void getContentFromUser(char *content);

/* Shows whole menu */
struct Task getTaskFromUser();

/* Shows whole menu */
void showList();

/* Shows whole menu */
void deleteTask();

/* Shows whole menu */
void editTask();

/* Shows whole menu */
void showStatistics();

#endif
