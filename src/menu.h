#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/* Shows whole menu */
void showMenu();

/* Shows logotype and version */
void showLogo();

/* Shows menu options */
void showMenuOptions();

/* Asks user and returns choice */
int getChoice();

/* Chooses actions based on user selection */
void selectOption(int option);

/* end program in pleasant way */
void exitMenu();

/* clear screen on Windows and Linux */
void clrScr();

/* print message and wait for input */
void makePause();

#endif
