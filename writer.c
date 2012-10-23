#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "q.h"

void* writer(sq **q){
    int count = 0;
    char *inputString;

    /* while not end of file, keep dequeue and print output */
    while (!sq_isDone(q[2])){
        inputString = sq_deq(q[2]);
        printf("%s", inputString);
        count++;
        free(inputString); /* frees up buffer */
    }
    /* after end of file */
    printf("Total number of lines: %d", count);
    return NULL;
}
