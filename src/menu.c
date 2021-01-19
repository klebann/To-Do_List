/* 00 system includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 01 project includes */
#include "menu.h"
#include "task.h"

void showMenu(){
    int choice;
    do {
        clrScr();
        showLogo();
        showMenuOptions();

        choice = getChoice();
        selectOption(choice);
    } while(choice != 0);
}

void showLogo(){
    printf(
        "  _____           ____          _     _     _       \n"
        " |_   _|__       |  _ \\  ___   | |   (_)___| |_    \n"
        "   | |/ _ \\ _____| | | |/ _ \\  | |   | / __| __|  \n"
        "   | | (_) |_____| |_| | (_) | | |___| \\__ \\ |_   \n"
        "   |_|\\___/      |____/ \\___/  |_____|_|___/\\__| \n"
        "\n"
        "To-Do List version 0.1 2021-01-05\n"
        "\n"
    );
}

void showMenuOptions(){
    puts("Options:");
    puts("  (1) Add new task");
    puts("  (2) Show list");
    puts("  (3) Delete task");
    puts("  (4) Edit task");
    puts("  (5) Show statistics");
    puts("  (0) Exit");
    puts("");
}

int getChoice(){
    printf("Enter your choice: ");
    int choice;
    scanf("%i", &choice);
    return choice;
}

void selectOption(int option){
    switch(option){
    case 1:
        addTask();
        break;
    case 2:
        showList();
        break;
    case 3:
        deleteTask();
        break;
    case 4:
        editTask();
        break;
    case 5:
        showStatistics();
        break;
    case 0:
        exitMenu();
        break;
    default:
        puts("Select option from 0-6 range");
        break;
    }
}

void exitMenu(){
    clrScr();
    printf(
           "  ________________                                                    \n"
           " < See            >                                                   \n"
           "  ----------------                                                    \n"
           " \\                             .       .                             \n"
           "  \\                           / `.   .' \"                           \n"
           "   \\                  .---.  <    > <    >  .---.                    \n"
           "    \\                 |    \\  \\ - ~ ~ - /  /    |                  \n"
           "          _____          ..-~             ~-..-~                      \n"
           "         |     |   \\~~~\\.'                    `./~~~/               \n"
           "        ---------   \\__/                        \\__/                \n"
           "       .'  O    \\     /               /       \\  \"                 \n"
           "      (_____,    `._.'               |         }  \\/~~~/             \n"
           "       `----.          /       }     |        /    \\__/              \n"
           "             `-.      |       /      |       /      `. ,~~|           \n"
           "                 ~-.__|      /_ - ~ ^|      /- _      `..-'           \n"
           "                      |     /        |     /     ~-.     `-. _  _  _  \n"
           "                      |_____|        |_____|         ~ - . _ _ _ _ _> \n"
    );

    sleep(1);
    clrScr();
    printf(
           "  ________________                                                    \n"
           " < See you        >                                                   \n"
           "  ----------------                                                    \n"
           " \\                             .       .                             \n"
           "  \\                           / `.   .' \"                           \n"
           "   \\                  .---.  <    > <    >  .---.                    \n"
           "    \\                 |    \\  \\ - ~ ~ - /  /    |                  \n"
           "          _____          ..-~             ~-..-~                      \n"
           "         |     |   \\~~~\\.'                    `./~~~/               \n"
           "        ---------   \\__/                        \\__/                \n"
           "       .'  O    \\     /               /       \\  \"                 \n"
           "      (_____,    `._.'               |         }  \\/~~~/             \n"
           "       `----.          /       }     |        /    \\__/              \n"
           "             `-.      |       /      |       /      `. ,~~|           \n"
           "                 ~-.__|      /_ - ~ ^|      /- _      `..-'           \n"
           "                      |     /        |     /     ~-.     `-. _  _  _  \n"
           "                      |_____|        |_____|         ~ - . _ _ _ _ _> \n"
    );

    sleep(1);
    clrScr();
    printf(
           "  ________________                                                    \n"
           " < See you later! >                                                   \n"
           "  ----------------                                                    \n"
           " \\                             .       .                             \n"
           "  \\                           / `.   .' \"                           \n"
           "   \\                  .---.  <    > <    >  .---.                    \n"
           "    \\                 |    \\  \\ - ~ ~ - /  /    |                  \n"
           "          _____          ..-~             ~-..-~                      \n"
           "         |     |   \\~~~\\.'                    `./~~~/               \n"
           "        ---------   \\__/                        \\__/                \n"
           "       .'  O    \\     /               /       \\  \"                 \n"
           "      (_____,    `._.'               |         }  \\/~~~/             \n"
           "       `----.          /       }     |        /    \\__/              \n"
           "             `-.      |       /      |       /      `. ,~~|           \n"
           "                 ~-.__|      /_ - ~ ^|      /- _      `..-'           \n"
           "                      |     /        |     /     ~-.     `-. _  _  _  \n"
           "                      |_____|        |_____|         ~ - . _ _ _ _ _> \n"
    );

    sleep(1);
    exit(EXIT_SUCCESS);
}

void clrScr()
{
    system("clear || cls");
}

void makePause(){
    printf("Press any key to continue...");
    getchar(); getchar();
}

