#include<stdio.h>

typedef struct linked_list_Node
{
	int node_val;
	struct linked_list_Node *next;

}llnode;

llnode *ptrHead = NULL;
llnode *ptrLast = NULL;

llnode *insert_node_linkedlist(int);
int delete_node_linkedlist(int);
void display_linkedlist();
