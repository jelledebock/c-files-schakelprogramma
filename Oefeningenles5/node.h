#ifndef _NODE_H 
#define _NODE_H
struct Node{
	int value;
	struct Node * next;
};

void add_to_front(int, struct Node **);
void print_list(const struct Node *);
void print_list_rec(const struct Node *);
void print(void (*write_function)(const struct Node *),const struct Node *);
struct Node * create_sorted_list(int n, int max);
void remove_duplicates(struct Node **);
void reverse(struct Node **);
struct Node * merge(const struct Node *, const struct Node *);
#endif
