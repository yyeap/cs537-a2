#include "q.h"
#include <semaphore.h>
#define MAX_SIZE 10

typedef struct synchedq {
  char* q_data[MAX_SIZE];
  int head;
  int size;
  int tail;
  sem_t enq_wait;
  sem_t dq_wait;
} sq;

void sq_init(sq q){
  head = 0;
  size = 0;
  tail = 0;
}

void sq_enq(sq q, char* new_item){
  /*p(enq_wait)*/
  /*set element at index tail to new_item pointer*/
  /*increment tail */
}

void* sq_deq(sq q){

  return null; /*return popped pointer*/
}

int sq_isEmpty(sq q){

  return 0 == size;
}
