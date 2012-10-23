#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q.h"

void writer(sq *q3){
    int count = 0;
    char *inputString, *curr;

    inputString = sq_deq(q3); /* dequeue */
    curr = inputString; /* set current char to the first char in inputString */

    /* while not end of file, keep dequeue and print output */
    while ('\x04' != *curr){
        printf("%s", inputString);
        count++;
        free(inputString); /* frees up buffer */
        inputString = sq_deq(q3); /* get next item in queue */
        curr = inputString;
    }
    printf("Total number of lines: %d", count);

}
