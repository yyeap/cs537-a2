typedef struct {
  char** data;
  int head;
  int size;
  sem_t open;
  sem_t filled;
} sq;

extern void sq_init(sq* q);

extern void sq_enq(sq* q, void *new_item);

extern void* sq_deq(sq* q);

extern int sq_isEmpty(sq* q);
