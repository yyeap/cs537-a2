#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "writer.h"
#include "synchq.h"

void* writer(void *q){
    printf("start writer\n");
    sq** queues = (sq**)q; /* cast to array of queues */
    int count = 0;
    char *inputString;
    printf("before writer while\n");
    /* while not end of file, keep dequeue and print output */
    while (!sq_isDone(queues[2])){
        inputString = sq_deq(queues[2]);
        printf("before printing result\n");
        printf("%s", inputString);
        printf("print result success\n");
        count++;
        free(inputString); /* frees up buffer */
    }
    /* after end of file */
    printf("Total number of lines: %d\n", count);
    return NULL;
}
