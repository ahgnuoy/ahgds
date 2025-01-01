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
    // "[p]previous [h]home [e]exit [c]cancel \n";
    "(e)xit\n";
    printf("%s", txt);
    printf("-----------------------------------------\n");
}

void select_menu_item(PageBreadcrumbs* pb, int count)
{
    printf("input> ");
    char input_value;
    scanf("%c", &input_value);
    if(input_value <= '9' && input_value > '0')
    {
        int input_number = input_value - '1';
        if(input_number > count)
        {
            printf("Not Valid\n");
            printf("input> ");
            select_menu_item(pb, count);
        }
        else
        {
            MenuItemNode* min = pb->top->min->children->head;
            for(int i = 0; i < input_number; i++) min = min->next;
            if(min->mi->job != NULL) min->mi->job();
            if(min->children->length != 0)
            {
                move_page(pb, min);
            }
        }
    }
    else
    {
        if(input_value == 'e')
        {
            exit_page(pb);
        }
    }
}

/**
 * @brief peek the top page node from page breadcrumbs and show contents of it
 * 
 * @param pb 
 */
void show_page(PageBreadcrumbs* pb, bool logo)
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    PageNode* pn = pb->top;
    MenuItemNode* min = pn->min;
    MenuItemGroup* mig = min->children;
    draw_navigation_guide();
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
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    printf("BYE\n");
    return;
}

void exit_page(PageBreadcrumbs* pb)
{
    draw_exit_message();
    pb->exit = true;
}