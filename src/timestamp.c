/* 00 system includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 01 project includes */
#include "timestamp.h"

time_t getTimestampFromUser(){
    printf("Date(YYYY.MM.DD HH:MM): ");
    char* date;
    scanf("");

    time_t result = 0;

    int year = 0, month = 0, day = 0, hour = 0, min = 0;

    if (sscanf(date, "%4d.%2d.%2d %2d:%2d", &year, &month, &day, &hour, &min) == 5) {
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
       return ctime(&result);
    }
    else {
      fprintf(stderr, "The input was not a valid time format\n");
      exit(EXIT_FAILURE);
    }
}
