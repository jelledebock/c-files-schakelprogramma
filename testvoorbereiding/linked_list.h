#ifndef linkedlist
#define linkedlist

#include <stdlib.h>
#include<stdio.h>


struct Node{
    int value;
    struct Node *next;
};

struct Node_Properties
{
    int size;
    struct Node *first;
    struct Node *last;
};

struct List{
    struct Node *list;
    struct Node_Properties *properties;
};

/* List functions */

struct List * init_list(){
    struct Node_Properties *properties = malloc(sizeof(struct Node_Properties));
    struct List * list = malloc(sizeof(struct List));

    properties->size = 0;

    properties->first = NULL;
    properties->last = NULL;



    list->properties = properties;
    list->list=NULL;
}

struct List * create_list(int *values, int n)
{
    struct Node_Properties *properties = malloc(sizeof(struct Node_Properties));
    struct List *list = malloc(sizeof(struct List));
    struct Node *tmp;
    int i = 0;

    properties->size = n;

    tmp = malloc(sizeof(struct Node));

    tmp->value = values[0];
    tmp->next = NULL;

    properties->first = tmp;
    list->list = tmp;

    for(i=1; i<n; i++)
    {
        tmp->next = malloc(sizeof(struct Node));
        tmp = tmp->next;

        tmp->value = values[i];
        tmp->next = NULL;
    }

    properties->last = tmp;

    list->properties = properties;

    return list;
}


void print_list(struct List **list)
{
    int n;
    struct Node *tmp = (*list)->list;

    n=(*list)->properties->size;

    printf("META---------\nThe list has %d elements. \nFirst element: %d\nLast element: %d\n",n,(*list)->properties->first->value,(*list)->properties->last->value);

    while(tmp)
    {
        printf("Element with value %d \n",tmp->value);
        tmp = tmp->next;
    }
}

void decrement_size(struct List **list)
{
    (*list)->properties->size--;
}

void increment_size(struct List **list)
{
    (*list)->properties->size++;
}

void set_first(struct List **list, struct Node *node)
{
    (*list)->properties->first = node;
}

void set_last(struct List **list, struct Node *node)
{
    (*list)->properties->last = node;
}

/*Sort can be 1 or 0 and indicates whether the list is sorted */
void add_element(int num, struct List **list, int sort)
{
    struct Node * new_node;
    struct Node * tmp2;

    int list_size = (*list)->properties->size;
    int i = 0;

    /*This is choice independent */
    new_node = malloc(sizeof(struct Node));
    new_node->value = num;

    if(list_size==0)
    {
        new_node->next = NULL;
        (*list)->list = new_node;
        set_first(list, new_node);
    }
    else
    {
        if(sort==0)
        {
            new_node->next = NULL;
            tmp2 = (*list)->properties->last;
            tmp2->next = new_node;
            (*list)->properties->last = new_node;
        }
        else
        {
            /*Find where the element needs to be added */
            tmp2 = (*list)->list;

            if(tmp2->value > num)
            {

                new_node->next = tmp2;
                (*list)->list = new_node;
                set_first(list, new_node);
            }
            else{
            while(tmp2->next != NULL && tmp2->next->value < num )
            {
                i++;
                tmp2 = tmp2->next;
            }

            new_node->next = tmp2->next;
            tmp2->next = new_node;
        
            }
        }

        if(i-1==0)
            set_first(list,new_node);
        if(i==list_size-1)
            set_last(list,new_node);
    }


    increment_size(list);
}

#endif
