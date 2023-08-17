typedef int data_t;
typedef struct linkstack
{
    data_t data;
    struct linkstack *next;
}linkstack;


linkstack *linkstack_creat();
int linkstack_free(linkstack *l);
int linkstack_push(linkstack *l,data_t value);
data_t linkstack_pop(linkstack *l);
int linkstack_empty(linkstack *l);
int linkstack_clear(linkstack *l);
void linkstack_top(linkstack *l,data_t *value);
void linkstack_show(linkstack *l);
