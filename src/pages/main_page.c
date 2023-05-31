#include "main_page.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "singly_linked_list_page.h"

/**
 * @brief dummy for testing create_menu_item function
 * 
 */
static void test()
{
    printf("do something worthless\n");
}

MenuItemNode* setup_menu()
{
    // menu explore
    // using tree structure
    MenuItemNode* rootMin = create_menu_item_node(NULL);
    MenuItem *menu1 = create_menu_item("Singly Linked List", test);
    MenuItem *menu2 = create_menu_item("Circular Linked List", test);
    MenuItemNode* node1 = create_menu_item_node(menu1);
    MenuItemNode* node2 = create_menu_item_node(menu2);
    add_child(rootMin, node1);
    singly_linked_list_setup_menu(node1);
    add_child(rootMin, node2);
    return rootMin;
}
