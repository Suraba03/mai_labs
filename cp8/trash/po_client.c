#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponomarev_header.h"

int main()
{
    int n;
    char a[20];
    char q;
    list l;
    printf("\nList of commands:\n\t\"create\" - create new list\n\t\"add_to_back\"- push back to list\n\t\"delete\" - delete element from list\n\t""\"add_with_index\" - add element to list with index\n\t\"print_list\" - printing list\n\t\"number_of_elements\" - prints numberof elements in list\n\t""\"reverse\" - task reverse of the list\n\t\"quit\" - for quitting the program\n\n");
    printf("Please enter command: ");
    scanf("%s%c", a, &q);
    
    while (!strcmp(a, "create") || !strcmp(a, "add_to_back") || !strcmp(a, "delete") || !strcmp(a, "add_with_index") ||!strcmp(a, "print_list") || !strcmp(a, "number_of_elements") || !strcmp(a, "reverse")) {
        if (!strcmp(a, "number_of_elements")) {
            number_of_elements_on_lists(&l);
        } else if (!strcmp(a, "create")) {
            list_create(&l, 0);
        } else if(!strcmp(a, "add_to_back")) {
            printf("Please enter element of list which you want add: ");
            scanf("%c", &q);
            push_back(&l, q);
        } else if(!strcmp(a, "delete")) {
            delete_element_of_list(&l);
        } else if(!strcmp(a, "add_with_index")) {
            list_add_index(&l);
        } else if(!strcmp(a, "print_list")) {
            list_print(&l);
        } else if(!strcmp(a, "reverse")) {
            reverse(&l);
        } else if(!strcmp(a, "quit")) {
            printf("Quit\n");
            return 0;
        }
        printf("Please enter new command: ");
        scanf("%s%c", a, &q);
    }
    printf("Error, command didn't found\n");
}