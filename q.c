#include "q.h"
#include <semaphore.h>
#define MAX_SIZE 10

typedef struct synchq {
  char* q_data[MAX_SIZE];
  int head;
  int size;
  int tail;
  sem_t enq_wait;
  sem_t dq_wait;
} synchQ;
