llnode *create_node(int val)
{
	llnode * ptrNode = NULL;
	if (!(ptrNode = (llnode *)malloc(sizeof(llnode))))
	{
		return NULL;
	}
	else
	{
		ptrNode->node_val = val;
		ptrNode->next = NULL;
		return ptrNode;
	}
}

llnode *initialize_linkedlist(int val)
{
	if (!(ptrHead = create_node(val)))
		return NULL;
	else
	{
		ptrLast = ptrHead;
		return ptrHead;
	}		
}

llnode *insert_node_linkedlist(int val)
{
	if (ptrHead == NULL)
		initialize_linkedlist(val);
	else
	{
		if (!((ptrLast->next) = create_node(val)))
			return NULL;
		else
		{
			ptrLast = ptrLast->next;
			return ptrLast;
		}
	}
}

llnode *search_node_linkedlist(int val)
{
	llnode *ptr = NULL;
	do
	{
		if (ptr)
			ptr = ptr->next;			
		else
			ptr = ptrHead;

	} while (ptr != ptrLast && ((ptr->next)->node_val) != val);

	if (ptr == ptrLast)
		return NULL;
	else
	{
		return ptr;
	}

}

int delete_node_linkedlist(int val)
{
	
	llnode *ptr;
	llnode *ptrT;
	if (ptrHead == NULL)
	{
		printf("Linked list is empty!..\n");
		return 1;
	}
		
	else if (ptrHead->node_val == val)
	{
		ptr = ptrHead;

		if (ptrHead->next != NULL)
			ptrHead = ptrHead->next;
		else
		{
			ptrHead = NULL;
			ptrLast = NULL;
		}
		free(ptr);
		return 1;

	}

	else
	{

		if (!(ptr = search_node_linkedlist(val)))
			return 0;
		else
		{

			ptrT = ptr->next;
			if (ptrLast == ptrT)
			{
				if (ptrHead == ptr)
				{
					ptrLast = ptrHead;
					ptrHead->next = NULL;
				}
				else
				{
					ptr->next = NULL;
					ptrLast = ptr;
				}
				
			}
			else
			{
				ptr->next = ptrT->next;
			}
			free(ptrT);
		}
	}
	return 1;
}

void display_linkedlist()
{
	llnode *ptr = ptrHead;
	int i = 0;
	if (ptr)
	{
		do
		{
			printf("->%d ", (ptr->node_val));
			ptr = ptr->next;

		} while (ptr != ptrLast && ptr != NULL);
		if (ptr != NULL)
			(printf("->%d ", (ptr->node_val)));
		printf("\n");
		return;
	}
	else
		printf("Linked list is empty!..\n");
		return;
	
}