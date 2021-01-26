#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

/**
 * Timestamps structure
 */
struct Timestamps{
    time_t creation; /**< creation timestamp */
    time_t begin; /**< task begin timestamp */
    time_t end; /**< task end timestamp */
};

/**
 * read date&time from user and convert it to Timestamp
 */
time_t getTimestampFromUser(char *message);

/**
 * Convert Timestamp to human readable date
 */
void printHumanReadableDate(time_t timestamp, char *message);

#endif
