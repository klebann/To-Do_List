#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

/**
 * read date&time from user and convert it to Timestamp
 */
time_t getTimestampFromUser(char *message);

/**
 * Convert Timestamp to human readable date
 */
void printHumanReadableDate(time_t timestamp, char *message);

#endif
