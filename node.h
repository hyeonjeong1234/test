#ifndef __NODE_H_
#define __NODE_H_
typedef struct node
{
    int id;
    int value;
    struct node* next;
}node_t;
#endif