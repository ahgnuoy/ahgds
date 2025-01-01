#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"pages/main_page.h"
#include"pages/page_service.h"

int main() 
{
    PageBreadcrumbs* pb = malloc(sizeof(PageBreadcrumbs));
    pb->top = NULL;
    pb->exit = false;
    MenuItemNode* min = setup_menu();
    move_page(pb, min);
    while(!pb->exit) show_page(pb, true);
    getchar();
    getchar();
    return 0;
}