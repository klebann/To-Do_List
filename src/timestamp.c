/* 00 system includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 01 project includes */
#include "timestamp.h"

time_t getTimestampFromUser(char *message){
    /* concatenation */
    char buff[100];
    strcpy(buff, message);
    strcat(buff, "date(YYYY.MM.DD HH:MM): ");

    printf(buff);

    time_t result = 0;

    int year = 0, month = 0, day = 0, hour = 0, min = 0;

    if (scanf("%4d.%2d.%2d %2d:%2d", &year, &month, &day, &hour, &min) == 5) {
       struct tm breakdown = {0};
       breakdown.tm_year = year - 1900; /* years since 1900 */
       breakdown.tm_mon = month - 1;
       breakdown.tm_mday = day;
       breakdown.tm_hour = hour;
       breakdown.tm_min = min;

       if ((result = mktime(&breakdown)) == (time_t)-1) {
          fprintf(stderr, "Could not convert time input to time_t\n");
          exit(EXIT_FAILURE);
       }
       return (long)result;
    }
    else {
      fprintf(stderr, "The input was not a valid time format\n");
      exit(EXIT_FAILURE);
    }
}

void printHumanReadableDate(time_t timestamp, char *message){
    struct tm ts;
    char buf[80];
    ts = *localtime(&timestamp);
    strftime(buf, sizeof(buf), "%Y.%m.%d %H:%M", &ts);

    char output[100];
    strcpy(output, message);
    strcat(output, buf);
    printf("%s\n", output);
}

