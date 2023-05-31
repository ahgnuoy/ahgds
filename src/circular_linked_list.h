#ifndef CLLIST_H_
#define CLLIST_H_

typedef struct circular_linked_list_node CircularLinkedListNode;
typedef struct circular_linked_list CircularLinkedList;

struct circular_linked_list_node {
    char *data;
    struct circular_linked_list_node *next;
};

struct circular_linked_list {
    int length;
    struct circular_linked_list_node *head;
};

#endif