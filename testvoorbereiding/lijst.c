#include <stdio.h>
#include "linked_list.h"

int main()
{
    int values[]={1,5,6,8,9};

    struct List *list = create_list(values, sizeof(values)/sizeof(int));
    
    printf("---------------\nInitial list \n---------------------------\n\n");    
    print_list(&list);

    add_element(2,&list,1);

    printf("---------------\nAfter sorted insert \n---------------------------\n\n");    
    print_list(&list);

    add_element(1000,&list,0);

    printf("---------------\nAfter unsorted insert \n---------------------------\n\n");    
    print_list(&list);
    

    add_element(0,&list,1);

    printf("---------------\nChange first insert \n---------------------------\n\n");    
    print_list(&list);
    
    add_element(1001,&list,1);

    printf("---------------\nChange last insert \n---------------------------\n\n");    
    print_list(&list);

    add_element(33,&list,1);

    printf("---------------\nSomewhere in the middle insert \n---------------------------\n\n");    
    print_list(&list);

}
