#include "page_service.h"
#include <stdio.h>
#include <stdlib.h>

void draw_logo() {
    char *logo = 
    "   ___    __                            \n  / _ |  / /  ___ _ ___  __ __ ___  __ __\n / __ | / _ \\/ _ `// _ \\/ // // _ \\/ // /\n/_/ |_|/_//_/\\_, //_//_/\\_,_/ \\___/\\_, / \n            /___/                 /___/  \n";
    printf(logo);
}

void draw_navigation_guide() {
    char *txt = 
    "[p]previous [h]home [e]exit [c]cancel \n";
    printf(txt);
}

int select_menu_item(PageBreadcrumbs* pb, int count)
{
    printf("input> ");
    int input_number;
    scanf("%d", &input_number);
    input_number = input_number - 1;
    if(input_number < count || input_number >= 0)
    {
        MenuItemNode* min = pb->top->min->children->head;
        for(int i = 0; i < input_number; i++) min = min->next;
        if(min->mi->job != NULL) min->mi->job();
        if(min->children->length != 0)
        {
            move_page(pb, min);
        }
        return input_number;
    }
    else
    {
        printf("Not Valid\n");
        printf("input> ");
        select_menu_item(pb, count);
    }
}

/**
 * @brief peek the top page node from page breadcrumbs and show contents of it
 * 
 * @param pb 
 */
void show_page(PageBreadcrumbs* pb, bool logo)
{
    system("cls");
    PageNode* pn = pb->top;
    MenuItemNode* min = pn->min;
    MenuItemGroup* mig = min->children;
    if(logo) draw_logo();
    int cnt = 0;
    for(MenuItemNode* tmin = mig->head; tmin != NULL; tmin = tmin->next)
    {
        printf("[%d] ", ++cnt);
        printf(tmin->mi->title);
        printf("\n");
    }
    select_menu_item(pb, cnt);
}

/**
 * @brief move to selected page
 * 
 * @param pb PageBreadcrumbs*
 * @param min MenuItemNode*
 */
void move_page(PageBreadcrumbs* pb, MenuItemNode* min)
{
    PageNode* npn = malloc(sizeof(PageNode)); // new page node
    npn->min = min;
    if(pb->top != NULL) npn->next = pb->top->next;
    pb->top = npn;
}

/**
 * @brief move to previous page
 * 
 * @param pb PageBreadcrumbs*
 */
void prev_page(PageBreadcrumbs* pb)
{
    PageNode* tpn = pb->top; // temp page node
    pb->top = tpn->next;
    free(tpn);
}

MenuItem* create_menu_item(char* title, void (*job)())
{
    MenuItem* mi = malloc(sizeof(MenuItem));
    mi->title = title;
    mi->job = job;
    return mi;
}

MenuItemGroup* create_menu_item_group()
{
    MenuItemGroup* mig = malloc(sizeof(MenuItemGroup));
    mig->head = NULL;
    mig->length = 0;
    return mig;
}

MenuItemNode* create_menu_item_node(MenuItem* mi)
{
    MenuItemNode* min = malloc(sizeof(MenuItemNode));
    min->mi = mi;
    min->next = NULL;
    min->children = create_menu_item_group();
    return min;
}

void add_child(MenuItemNode* parent, MenuItemNode* child)
{
    append_menu_item_group(parent->children, child);
}

void append_menu_item_group(MenuItemGroup* mig, MenuItemNode* node)
{
    if(mig->head == NULL)
    {
        mig->head = node;
    }
    else
    {
        MenuItemNode* tn = mig->head;
        while(tn->next != NULL)
        {
            tn = tn->next;
        }
        tn->next = node;
    }
    mig->length++;
}

void draw_exit_message()
{
    system("cls");
    printf("BYE\n");
    return;
}