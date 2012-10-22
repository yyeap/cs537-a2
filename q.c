#include "q.h"
#include <semaphore.h>
#define MAX_SIZE 10

typedef struct synchedq {
  char* q_data[MAX_SIZE];
  int head;
  int size;
  sem_t open;
  sem_t filled;
} sq;

void sq_init(sq q){
  head = 0;
  size = 0;
  sem_init(&open, 0, MAX_SIZE);
  sem_init(&filled, 0, 0);
}

void sq_enq(sq q, char* new_item){
  sem_wait&(&open);
  q_data[(head + size % MAX_SIZE)] = new_item;
  size++;
  sem_post(&filled); 
  /*p(enq_wait)*/
  /*set element at index tail to new_item pointer*/
  /*increment tail */
}

void* sq_deq(sq q){
  sem_wait(&filled);
  size--;
  int loc = head;
  head = (head + 1) % MAX_SIZE;
  sem_post(&open);
return q_data[loc]; /*return popped pointer*/
}

int sq_isEmpty(sq q){
  return 0 == size;
}
/*DONT FORGET TO DESTROY SEMAPHORES*/
