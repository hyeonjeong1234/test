#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_lv0.h"

/* void print_node(const node_t* head); // 자유구현*/

node_t* get_node_or_null(node_t* head, int id)
 {
    const node_t *now = head;
    int find = 0;
    while(now->next!=NULL)
    {
        if(now->id==id)
        {
            find = 1;
            break;
        }
        else
        {
            now = now->next;
        }
    }
    if(find == 1)
    {
        return now;
    }
    else
        return FALSE;
}
int add(node_t** phead, node_t node)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->id= node.id;
    new_node->value = node.value;
    new_node->next = NULL;
    if(phead == NULL)
    {
        *phead = new_node;
        return TRUE;
    }
    else
    {
        new_node->next = *phead;
        *phead = new_node;
        return TRUE;

    }   
}
int remove_node(node_t** phead, int id)
{
    //node_t * next = (*phead)->next;
    node_t *now = (*phead);
    node_t *front = NULL;
    int find = 0;
    printf("start REMOVE_NODE");
    while(1)
    {
        if(now->id==id)
        {
            find = 1;
            break;
        }
        else
        {
            front = now;
            if(now->next == NULL)
                break;
            else
                now = now->next;
        }
    }
    if(front != NULL&&find == 1)
    {
        front->next = now->next;
        if(now!=NULL)
        {
            free(now);
            now = NULL;
            printf("success REMOVE_NODE"); 
            return TRUE;
        }
       else
       {
        printf("no REMOVE_NODE");
        return FALSE;
       }
        
    }
    else if(front == NULL&&find ==1)
    {
        *phead = now->next;
        if(now!=NULL)
        {
            free(now);
            now = NULL;
            return TRUE;
        }
        else
            FALSE;
    }
    else
        return FALSE;
    
}

void destroy(node_t** phead)
{
    node_t* delete_node = NULL;
    delete_node = *phead;
    while(delete_node->next !=NULL)
    {
        delete_node= delete_node->next;
        free(delete_node);
    }
    phead = NULL;
}