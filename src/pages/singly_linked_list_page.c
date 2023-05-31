#include "singly_linked_list_page.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static SinglyLinkedList* sll;

void singly_linked_list_setup_menu(MenuItemNode* min)
{
    sll = MakeSinglyLinkedList();

    MenuItem* menu1 = create_menu_item("Insert Item", singly_linked_list_insert_item);
    MenuItem* menu2 = create_menu_item("Delete Item", singly_linked_list_delete_item);
    MenuItem* menu3 = create_menu_item("Print List", singly_linked_list_print_list);
    MenuItem* menu4 = create_menu_item("Save List", singly_linked_list_save_list);
    MenuItem* menu5 = create_menu_item("Load List", singly_linked_list_load_list);

    MenuItemNode* node1 = create_menu_item_node(menu1);
    MenuItemNode* node2 = create_menu_item_node(menu2);
    MenuItemNode* node3 = create_menu_item_node(menu3);
    MenuItemNode* node4 = create_menu_item_node(menu4);
    MenuItemNode* node5 = create_menu_item_node(menu5);

    add_child(min, node1);
    add_child(min, node2);
    add_child(min, node3);
    add_child(min, node4);
    add_child(min, node5);
}

void singly_linked_list_insert_item()
{
    system("cls");
    printf("[1] Input New Value : \n");
    char new_value[50] = "";
    scanf("%s", new_value);
    printf("[2] Input Index [current list length is %d]: \n", sll->length);
    int index = 0;
    scanf("%d", &index);
    if(index == 0)
    {
        if(strlen(new_value) > 0) InsertSinglyLinkedListNode(sll, sll->length - 1, new_value);
    }
    else
    {
        if(strlen(new_value) > 0) InsertSinglyLinkedListNode(sll, index, new_value);
    }
}

void singly_linked_list_delete_item()
{
    system("cls");
    printf("1. Input Index : \n");
    int index;
    scanf("%d", &index);
    if(index >= 0) DeleteSinglyLinkedListNode(sll, index);
}

void singly_linked_list_print_list()
{
    PrintSinglyLinkedListNode(sll);
    getchar();
    getchar();
}

void singly_linked_list_load_list()
{
    free(sll);
    sll = MakeSinglyLinkedList();
    ReadFile(sll);
    printf("Read");
    getchar();
    getchar();
}

void singly_linked_list_save_list()
{
    SaveFile(sll);
    printf("Save");
    getchar();
    getchar();
}