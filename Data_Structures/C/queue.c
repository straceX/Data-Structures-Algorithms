/*first you have to call initialize_queue() function*/
int *initialize_queue(size_t size)
{
	SIZE = size;
	if (!(ptrQueue = ((int *)malloc(sizeof(int)* size))))
		return NULL;
	else
		return ptrQueue;
}

int is_queue_empty()
{
	if (front == -1) {
		printf("\nQueue is empty!..\n");
		return 1;
	}
	else
		return 0;
}
int is_queue_full()
{
	if ( (front == 0 && rear == SIZE - 1) || (front == (rear +1)) ) {
		printf("\n Queue is full\n");
		return 1;
	}
	else
		return 0;
}

void enqueue(int val)
{
	if (is_queue_full())
		return;
	else if (front == -1 && rear == -1)
	{
		front = rear = 0;
		ptrQueue[rear] = val;

	}
	else if (rear == SIZE - 1 && front != 0)
	{
		rear = 0;
		ptrQueue[rear] = val;
	}
	else
	{
		++rear;
		ptrQueue[rear] = val;
	}
}

int dequeue()
{
	int element = -1;

	if (is_queue_empty())
		return -1;

	element = ptrQueue[front];

	if (front == rear)
		front = rear = -1;
	else
	{
		if (front == SIZE - 1)
			front = 0;
		else
			++front;

	}

	return element;

}
void display_queue()
{
	int iter;
	if (!is_queue_empty())
	{
		printf("\n The queue elements are:\n ");
		printf("-->|");

		if (front != 0 && front > rear)
		{
			for (iter = rear; iter >= 0; --iter)
			{
				printf("\t %d", ptrQueue[iter]);
			}
			for (iter = SIZE-1; iter >= front; --iter)
			{
				printf("\t %d", ptrQueue[iter]);
			}

		}
		else
		{
			for (iter = rear; iter >= front; --iter)
			{
				printf("\t %d", ptrQueue[iter]);
			}
		}
		printf("\t|-->\n");
	}

	return;
}