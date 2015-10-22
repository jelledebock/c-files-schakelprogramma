#include <stdio.h>
#include "node.h"

int main()
{
	struct Node * list = create_sorted_list(7,8);
	printf("Before reverse:\n");
	print(print_list, list);
	printf("\nAfter reverse:\n");
	reverse(&list);
	print(print_list, list);
	printf("\n");	
}
