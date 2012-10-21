typedef struct synchedq sq
void sq_init(sq q);
void sq_enq(sq q, void *ptr);
void* sq_deq(sq q);
int sq_isEmpty(sq q);
