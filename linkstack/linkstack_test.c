#include<stdio.h>
#include<stdlib.h>
#include"../linkstack/linkstack.h"


int main(int argc, char const *argv[])
{
    linkstack *l;
    data_t value;
    l=linkstack_creat();
    linkstack_push(l,1);
    linkstack_push(l,2);
    if(linkstack_empty(l))
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("the stack is not empty\n");
    }
    linkstack_top(l,&value);
    printf("top is %d\n",value);
    linkstack_show(l);
    linkstack_free(l);
    return 0;
}
