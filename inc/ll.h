#ifndef __LL_H__
#define __LL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// linked list
typedef struct ll_node {
    int data;
    struct ll_node *next;
} ll_node_t;

// size
int ll_size(ll_node_t *head);

// print
void ll_print(ll_node_t *head);

// insert at head (push front)
void ll_insert_head(ll_node_t **head, int data);

// insert at tail (push back)
void ll_insert_tail(ll_node_t **head, int data);

// sort
void ll_sort(ll_node_t **head);

// nth node
int ll_nth_node(ll_node_t *head, int n);

// delete
void ll_delete(ll_node_t **head, int data);


#endif