#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"

//
//
linkstack *linkstack_creat()
{
    linkstack *l=NULL;
    l=(linkstack*)malloc(sizeof(linkstack));
    if(l==NULL)
    {
        printf("creating is fail\n");
        return 0;
    }
    l->data=-1;
    l->next=NULL;
    return l;
}
//
//
int linkstack_free(linkstack *l)
{
    linkstack *sl;
    while(l->next!=NULL)
    {
        sl=l->next;
        l->next=l->next->next;
        printf("free %d\t",sl->data);
        free(sl);
    }
    printf("free %d\t",l->data);
    free(l);
    return 0;
}
//
//
int linkstack_push(linkstack *l,data_t value)
{
    if(l==NULL)
    {
        printf("the stack is fail\n");
        return 0;
    }
    linkstack *sl=NULL;
    sl=(linkstack *)malloc(sizeof(linkstack));
    sl->data=value;
    sl->next=l->next;
    l->next=sl;
    // sl->next=l;
    // l=sl;
    //l=sl;l为参变量无法改变
    return 1;
}
data_t linkstack_pop(linkstack *l)
{
    if(l==NULL||l->next==NULL)
    {
        printf("the stack is fail\n");
        return 0;
    }
    data_t sd;
    linkstack *sl;
    sd=l->next->data; 
    sl=l->next;
    l->next=l->next->next;
    // sd=l->data;
    // sl=l;
    // l=l->next;
    free(sl);
    return sd;
}
//
//
int linkstack_empty(linkstack *l)
{
    if(l==NULL)
    {
        printf("the stack is fail\n");
        return 1;
    }
    // if (l->next==NULL)
    // {
    //     printf("the stack is empty\n");
    //     return 1;
    // }
    // return 0;
    return (l->next==NULL? 1:0);
    
}
//
//
int linkstack_clear(linkstack *l)
{
    if(l==NULL)
    {
        printf("the stack is fail\n");
        return 0;
    }
    while(l->next!=NULL)
    {
        linkstack *sl;
        sl=l->next;
        l->next=l->next->next;
        printf("free %d\t",sl->data);
        free(sl); 
    }
    return 1;
}
//
//
void linkstack_top(linkstack *l,data_t *value)
{
    if(l==NULL)
    {
        printf("the stack is fail\n");
    }
    *value=l->next->data;
}
//
//
void linkstack_show(linkstack *l)
{
    if(l==NULL)
    {
        printf("the stack is fail\n");
    }
    linkstack *sl=l;
    while(sl!=NULL)
    {
        printf("%d\t",sl->data);
        sl=sl->next;
    }
}