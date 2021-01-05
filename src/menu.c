#include "menu.h"

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

void showMenu(){
    showLogo();
    showMenuOptions();

    int choice = getChoice();
    printf("%i\n", choice);
}
