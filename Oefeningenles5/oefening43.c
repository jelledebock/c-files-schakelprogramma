#include <stdio.h>
#include "node.h"

int main()
{
	struct Node * list = NULL;
	add_to_front(7,&list);

	add_to_front(100,&list);

	print(&print_list,list);
	printf("\n");
	print(&print_list_rec,list);
	printf("\n");
}
