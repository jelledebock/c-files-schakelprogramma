#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "node.h"

void add_to_front(int value, struct Node **node)
{
	struct Node * tmp;

	if(node == NULL)
	{
		*(node) = malloc(sizeof(struct Node));
		(*node)->value = value;
		(*node)->next = NULL;
	}
	else
	{
		tmp = malloc(sizeof(struct Node));
		tmp->value = value;
		tmp->next = *node;
		*node = tmp;
	}
}
void print_list(const struct Node * node)
{
	const struct Node * tmp;
	tmp = node;

	while(tmp != NULL)
	{
		printf("%d\t",tmp->value);
		tmp = tmp->next;
	}
}

void print_list_rec(const struct Node *node)
{
	if(node != NULL)
	{
		printf("%d\t",node->value);
		print_list_rec(node->next);
	}
}

void print(void (*write_function)(const struct Node *), const struct Node * node)
{
	(*write_function)(node);
}

struct Node * create_sorted_list(int n, int max)
{
	int i=0;
	int value = 0;

	struct Node * node = malloc(sizeof(struct Node));
	struct Node * tmp;
	srand(time(NULL));

	node->value = max;
	node->next = NULL;

	for(i=1; i<n; i++)
	{
		value = node->value - rand() % 2;
		tmp = malloc(sizeof(struct Node));
		tmp->value = value;
		tmp->next = node ;
		node = tmp;
	}
	return node;
}

void remove_duplicates(struct Node **list)
{
	struct Node * tmp = *list;
	struct Node * helper;
	while(tmp != NULL)
	{
		while(tmp->next != NULL && tmp->value == tmp->next->value)
		{
			helper = tmp->next;
			tmp->next = helper->next;
			free(helper);
		}
		tmp = tmp->next;
	}
}
void reverse(struct Node **list)
{
	struct Node * next_node;
        struct Node * tmp;

	next_node = (*list)->next;
	(*list)->next = NULL;

	while(next_node != NULL)
	{
		tmp = next_node;
		next_node = next_node->next;

		tmp->next = (*list);
		(*list)=tmp;
	}
}

struct Node * merge(const struct Node * a, const struct Node * b){
	struct Node * merged;
	struct Node * tmp;

     	if(a->value < b->value)
	{
		merged = malloc(sizeof(struct Node));
		*merged = *(a);
		a = a->next;
	}	
	else
	{
		merged = malloc(sizeof(struct Node));
		*merged = *(b);
		b = b->next;
	}
	
	tmp = merged;

	while(a != NULL && b != NULL)
	{
		tmp = malloc(sizeof(struct Node));
		if( a->value < b->value )
		{
			*tmp = *(a);
			a = a->next;
		}
		else
		{
			*tmp = *(b);
			b = b->next;
		}
		tmp = tmp->next;
	}

	while(a != NULL)
	{
		tmp = malloc(sizeof(struct Node));	
		*tmp = *(a);
		a = a->next;
		tmp = tmp->next;
	}

	while(b != NULL)
	{
		tmp = malloc(sizeof(struct Node));
		*tmp = *(b);
		b = b->next;
		tmp = tmp->next;
	}
	tmp = NULL;

	return merged;
}
