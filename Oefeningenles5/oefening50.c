#include <stdio.h>
#include "node.h"

int main()
{
    struct Node * list;

    add_number(&list,1);
    print(print_list, list);
    printf("\n");
    add_number(&list,45);
    print(print_list, list);
    printf("\n");
    add_number(&list,3);
    print(print_list, list);
    printf("\n");
    add_number(&list,46);
    print(print_list, list);
    printf("\n");
    add_number(&list,103);

    print(print_list, list);
    printf("\n");
    
    remove_node(46,&list);
    print(print_list, list);
    printf("\n");


    remove_node(103,&list);
    print(print_list, list);
    printf("\n");

    clean_list(&list);
}
