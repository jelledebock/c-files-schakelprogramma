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
    
    if(*a && *b)
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
    
	    while(*a && *b)
	    {
            tmp = tmp->next;
            if((*a)->value < (*b)->value )
		    {
		        
                tmp = *a;	
			    *a = (*a)->next;
		    }
		    else
		    {
		        tmp = *b;
        	    *b = (*b)->next;
		    }
	    }
    }
    if(*a == NULL)
    {
        tmp->next = *b;
    }
    if(*b == NULL)
    {
        tmp->next = *a;
    }

    *a = NULL;
    *b = NULL;

	return merged;
}

struct Node ** search_ordered(int number, struct Node ** list)
{
    while((*list) && (*list)->value < number)
    {
       list=&((*list)->next);
    }
    return list;
}

void add_number(struct Node **list, int number)
{
    struct Node ** tmp;
    struct Node * next;
    struct Node * tmp2;

    tmp = search_ordered(number, list);
    next = (*tmp); 
    tmp2 = malloc(sizeof(struct Node));
    tmp2->next = next;
    tmp2->value = number;
    (*tmp) = tmp2;
}

void clean_list(struct Node **list)
{
    if(!(*list)->next)
    {
        free(*list);
    }
    else
    {
        clean_list(&((*list)->next));
    }
}

void remove_node(int number, struct Node **list)
{
    struct Node ** tmp = search_ordered(number, list);
    struct Node * tmp2;

    if((*tmp) && (*tmp)->value == number)
    {
        tmp2=(*tmp);
        (*tmp) = tmp2->next;
        free(tmp2);
    }
}
