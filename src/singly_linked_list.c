#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

SinglyLinkedListNode *CreateNode(char *data) {
    SinglyLinkedListNode *newNode = malloc(sizeof(SinglyLinkedListNode));
    char *newData = malloc(strlen(data)+1);
    if(!newNode) return NULL;
    strcpy(newData, data);
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void DeleteNode(SinglyLinkedListNode *node) {
    free(node);
    return;
}

void ChangeNext(SinglyLinkedListNode *node, SinglyLinkedListNode *next) {
    node->next = next;
    return;
}

SinglyLinkedList *MakeSinglyLinkedList() {
    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));
    list->head = NULL;
    list->length = 0;
}

void InsertSinglyLinkedListNode(SinglyLinkedList *list, int index, char *value) {
    int indexFromHead = list->length - index - 1;
    if(indexFromHead == 0) {
        SinglyLinkedListNode *newNode = CreateNode(value);
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        SinglyLinkedListNode *prevNode = list->head;
        for(int i = 1; i < indexFromHead; i++) {
            prevNode = prevNode->next;
        }
        SinglyLinkedListNode *newNode = CreateNode(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    list->length++;
}

void DeleteSinglyLinkedListNode(SinglyLinkedList *list, int index) {
    SinglyLinkedListNode *node = list->head;
    SinglyLinkedListNode *preNode;
    int indexFromHead = list->length - index - 1; 
    if(indexFromHead < 0) return;
    if(indexFromHead == 0) {
        list->head = node->next;
        DeleteNode(node);
        list->length--;
    }
    else {
        for(int i = 0; i < indexFromHead; i++) {
            if(i == indexFromHead - 1) preNode = node;
            node = node->next;
        }
        if(indexFromHead == list->length) ChangeNext(preNode, NULL);
        else ChangeNext(preNode, node->next);
        DeleteNode(node);
        list->length--;
    }
}

void PrintSinglyLinkedListNode(SinglyLinkedList *list)
{
    int index = list->length - 1;
    SinglyLinkedListNode *currentNode = list->head;
    while(currentNode != NULL) {
        printf("\n-----------NODE-----------");
        printf("\n|addr : %p |", currentNode);
        printf("\n|index: %16d |", index--);
        printf("\n|data : %16s | ", currentNode->data);
        printf("\n|next : %p |", currentNode->next);
        currentNode = currentNode->next;
    }
    printf("\n-----------EOL------------");
    printf("\nlength : %d", list->length);
}

void ReadFile(SinglyLinkedList *list)
{
    FILE *fp;
    // it worked not now
    // char* buffer
    char buffer[100];
    fp = fopen("./my-data.txt","r+");
    if (fp == NULL) return;

    while(!feof(fp))
    {
        fscanf(fp, "%s\n", buffer);
        InsertSinglyLinkedListNode(list, list->length - 1, buffer);
    }

    fclose(fp);
    return;
}

void SaveFile(SinglyLinkedList *list)
{
    FILE *fp;

    fp = fopen("./my-data.txt","w+");
    if (fp == NULL) return;

    ReverseSinglyLinkedList(list);
    SinglyLinkedListNode *currentNode = list->head;
    while(currentNode != NULL) {
        fprintf(fp, currentNode->data);
        fprintf(fp, "\n");
        currentNode = currentNode->next;
    }
    ReverseSinglyLinkedList(list);
    fclose(fp);
    return;
}

void ReverseSinglyLinkedList(SinglyLinkedList *list)
{
    SinglyLinkedListNode *prevNode = NULL;
    SinglyLinkedListNode *currNode = list->head;
    SinglyLinkedListNode *nextNode;
    while(currNode!= NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    list->head = prevNode;
    return;
}