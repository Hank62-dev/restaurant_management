#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

#define MAX_MENU_ITEMS 100

// Đọc menu từ file
int loadMenuFromFile(MenuItem menuList[], int *count) {
	
    FILE *file = fopen("menu.txt", "r");
    
    if (!file) return 0;
    
    *count = 0;
    
    while (fscanf(file, "%d %s %s %f %d", &menuList[*count].menuId, menuList[*count].dishName, menuList[*count].category,
                  &menuList[*count].price) == 4) {
        (*count)++;
    }
    
    fclose(file);
    
    return 1;
}

// In menu
void printMenu(MenuItem menuList[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d %s %s %.2f %d\n", menuList[i].menuId, menuList[i].dishName,
               menuList[i].category, menuList[i].price);
    }
}
