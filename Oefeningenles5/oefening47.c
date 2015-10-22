#include <stdio.h>
#include "node.h"

int main()
{
    struct Node * list;

    add_number(&list,1);
    add_number(&list,45);
    add_number(&list,3);

    print(print_list, list);
}
