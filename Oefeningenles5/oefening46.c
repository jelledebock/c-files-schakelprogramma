#include <stdio.h>
#include "node.h"

int main(){
	struct Node * m = create_sorted_list(5,1000);
	struct Node * n = create_sorted_list(5,100);
	printf("\nList m:\n"); print_list(m);
	printf("\n");
	printf("\nList n:\n"); print_list(n);
	printf("\n");
	printf("\nDeze worden gemerged. \n\n");
	printf("\n");
	struct Node * mn = merge(m,n);
	printf("\nList m:\n"); print_list(m);
	printf("\n");
	printf("\nList n:\n"); print_list(n);
	printf("\n");
  	printf("\nList mn:\n"); print_list(mn);
	printf("\n");
}
