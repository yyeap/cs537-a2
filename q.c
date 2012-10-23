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
  q->done = 0;
  sem_init(&q->open, 0, MAX_SIZE);
  sem_init(&q->filled, 0, 0);
}

void sq_enq(sq* q, char* new_item)
{
  /*wait for space for an element*/
  sem_wait(&q->open);

  /*enqueue the new item*/
  q->data[q->head + q->size % MAX_SIZE] = new_item;
  q->size++;

  /*indicate that a space was filled*/
  sem_post(&q->filled); 
}

void* sq_deq(sq* q)
{
  int loc;

  /*wait for an available item*/
  sem_wait(&q->filled);

  /*dequeue the item*/
  loc = q->head;
  q->size--;
  q->head = (q->head + 1) % MAX_SIZE;

  /*indicate that space for an element was opened*/
  sem_post(&q->open);

  return q->data[loc];
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

void sq_done(sq* q)
{
  q->done = 1;
}

int sq_isDone(sq* q)
{
  return q->done;
}
