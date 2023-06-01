#ifndef PAGESERVICE_H_
#define PAGESERVICE_H_
#include <stdbool.h>

typedef struct page_breadcrumbs PageBreadcrumbs;
typedef struct page_node PageNode;
typedef struct menu_item MenuItem;
typedef struct menu_item_group MenuItemGroup;
typedef struct menu_item_node MenuItemNode;

// stack carring menu item node
struct page_breadcrumbs
{
    PageNode* top;
    bool exit;
};

struct page_node
{
    MenuItemNode* min;
    PageNode* next;
};

struct menu_item
{
    void (*job)();
    char* title;
};

struct menu_item_group
{
    MenuItemNode* head;
    int length;
};

struct menu_item_node
{
    MenuItem* mi;
    MenuItemNode* next;
    MenuItemGroup* children;
};

void select_menu_item(PageBreadcrumbs *pb, int count);
void draw_logo();
void draw_navigation_guide();
void draw_exit_message();
MenuItem* create_menu_item(char*, void (*job)());
MenuItemNode* create_menu_item_node(MenuItem*);
MenuItemGroup* create_menu_item_group();
void add_child(MenuItemNode* parent, MenuItemNode* child);
void append_menu_item_group(MenuItemGroup*, MenuItemNode*);

void show_page(PageBreadcrumbs* pb, bool logo);
void move_page(PageBreadcrumbs* pb, MenuItemNode* min);
void prev_page(PageBreadcrumbs* pb);
void exit_page(PageBreadcrumbs* pb);
#endif