#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

/* read date&time from user and convert it to timestamp */
time_t getTimestampFromUser(char *message);

void printHumanReadableDate(time_t timestamp, char *message);

#endif
