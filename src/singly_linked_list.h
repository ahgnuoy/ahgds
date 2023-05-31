#ifndef SLLIST_H_
#define SLLIST_H_

typedef struct singly_linked_list_node SinglyLinkedListNode;
typedef struct singly_linked_list SinglyLinkedList;

struct singly_linked_list_node {
    char *data;
    struct singly_linked_list_node *next;
};

struct singly_linked_list {
    int length;
    SinglyLinkedListNode *head;
};

SinglyLinkedListNode *CreateNode(char *data);
void DeleteNode(SinglyLinkedListNode *node);
void ChangeNext(SinglyLinkedListNode *node, SinglyLinkedListNode *next);
SinglyLinkedList *MakeSinglyLinkedList();
void InsertSinglyLinkedListNode(SinglyLinkedList *list, int index, char *value);
void DeleteSinglyLinkedListNode(SinglyLinkedList *list, int index);
void PrintSinglyLinkedListNode(SinglyLinkedList *list);
void ReadFile(SinglyLinkedList *list);
void SaveFile(SinglyLinkedList *list);
void ReverseSinglyLinkedList(SinglyLinkedList *list);

#endif