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

struct Node * merge(struct Node ** a, struct Node ** b){
    struct Node * merged = NULL;
    struct Node * tmp = NULL;
    
    if(*a != NULL && *b != NULL)
    {
        if((*a)->value < (*b)->value)
        {
            merged = *a;
            *a = (*a)->next;
        }
        else
        { 
           merged = *b; 
           *b = (*b)->next;
        }

        tmp = merged;
    
	    while(*a != NULL && *a != NULL)
	    {
            if((*a)->value < (*b)->value )
		    {
		        
                tmp->next = *a;	
			    *a = (*a)->next;
		    }
		    else
		    {
		        tmp->next = *b;
        	    *b = (*b)->next;
		    }
            tmp = tmp->next;
	    }
    }
    else if(*a == NULL)
    {
        tmp = *b;
    }
    else if(*b == NULL)
    {
        tmp = *a;
    }

    tmp->next = NULL;
    *a = NULL;
    *b = NULL;

	return merged;
}

void add_number(struct Node **list, int number)
{
    struct Node * tmp;
    struct Node * helper = *list;
     
    while(helper != NULL && helper->value < number)
    {
        helper = helper->next;
    }
    
    tmp = malloc(sizeof(struct Node));
    tmp->value = number;
    tmp->next = helper->next;
    helper->next = tmp;
}
