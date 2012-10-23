#include "q.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void sq_init(sq* q)
{
  char* new_array[MAX_SIZE];
  q->data = new_array;
  q->head = 0;
  q->size = 0;

  sem_init(&q->open, 0, MAX_SIZE);
  sem_init(&q->filled, 0, 0);
}

void sq_enq(sq* q, char* new_item)
{
  sem_wait(&q->open);

  q->data[q->head + q->size % MAX_SIZE] = new_item;
  q->size++;

  sem_post(&q->filled); 
}

void* sq_deq(sq* q)
{
  int loc;

  sem_wait(&q->filled);

  loc = q->head;
  q->size--;
  q->head = (q->head + 1) % MAX_SIZE;

  sem_post(&q->open);

  return q->data[loc]; /*return popped pointer*/
}

int sq_isEmpty(sq* q)
{
  return 0 == q->size;
}

void sq_destroy(sq* q)
{
  sem_destroy(&q->open);
  sem_destroy(&q->filled);
  free(q);
}
