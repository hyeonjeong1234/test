#ifndef __LINKEDLIST_LV0__H_
#define __LINKEDLIST_LV0__H_

#include "node.h"

#define TRUE (1)
#define FALSE (0)

/* void print_node(const node_t* head); // 자유구현*/

node_t* get_node_or_null(node_t* head, int id);

int add(node_t** phead, node_t node);

int remove_node(node_t** phead, int id);

void destroy(node_t** phead);

#endif