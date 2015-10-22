#include <stdio.h>
#include "node.h"

int main()
{
	struct Node * list = create_sorted_list(5,5);
	printf("With duplicates: \n");
	print(print_list, list);
	printf("\n");
	printf("Without duplicates: \n");
	remove_duplicates(&list);
	print(print_list_rec, list);
	printf("\n");
}
