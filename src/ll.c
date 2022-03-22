#include "../inc/ll.h"

// size
int ll_size(ll_node_t* head){
    int size = 0;
    ll_node_t* current = head;
    while(current != NULL){
        size++;
        current = current->next;
    }
    return size;
}

// print 
void ll_print(ll_node_t* head){
    ll_node_t* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// insert at head (push front)
void ll_insert_head(ll_node_t** head, int data){
    ll_node_t* new_node = (ll_node_t*)malloc(sizeof(ll_node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// insert at tail (push back)
void ll_insert_tail(ll_node_t** head, int data){
    ll_node_t* new_node = (ll_node_t*)malloc(sizeof(ll_node_t));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }else{
        ll_node_t* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
}

// sort
void ll_sort(ll_node_t** head){
    ll_node_t* current = *head;
    ll_node_t* previous = NULL;
    ll_node_t* next = NULL;
    while(current != NULL){
        next = current->next;
        while(next != NULL && next->data < current->data){
            previous = next;
            next = next->next;
        }
        if(next == current){
            current = current->next;
        }else{
            if(previous == NULL){
                *head = next;
            }else{
                previous->next = next;
            }
            current->next = next;
            previous = current;
            current = next;
        }
    }
}

// nth node
int ll_nth_node(ll_node_t* head, int n){
    ll_node_t* current = head;
    while(current != NULL && n > 0){
        current = current->next;
        n--;
    }
    return current->data;
}

// delete
void ll_delete(ll_node_t** head, int data){
    if(*head == NULL){
        return;
    }
    ll_node_t* current = *head;
    ll_node_t* previous = NULL;
    while(current != NULL){
        if(current->data == data){
            if(previous == NULL){
                *head = current->next;
            }else{
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

