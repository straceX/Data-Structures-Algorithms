void swap2int(int *val1, int *val2)
{
	if (*val1 != *val2)
	{
		*val1 = (*val1) ^ (*val2);
		*val2 = (*val1) ^ (*val2);
		*val1 = (*val1) ^ (*val2);
	}
	return;

}

int *gnome_sort(int ptrArray[], const size_t size)
{
	int tmp;
	size_t iter		= 1;
	size_t jiter	= 2;

	if (!size)
		return NULL;

	while (iter < size)
	{
		if (ptrArray[iter - 1] > ptrArray[iter])
		{

			swap2int(ptrArray + iter, ptrArray + iter - 1);
			if (--iter)
				continue;
				
		}
		iter = jiter++;
	}
	return ptrArray;

}