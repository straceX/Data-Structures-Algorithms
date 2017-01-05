void swap2int(int *val1, int *val2)
{
	*val1 = (*val1) ^ (*val2);
	*val2 = (*val1) ^ (*val2);
	*val1 = (*val1) ^ (*val2);
}

int *odd_even_transposition_sort(int *ptrArray, size_t length)
{
	int swapped = 1, iter, size;

	if (!length || !ptrArray)
		return NULL;

	while (swapped)
	{
		swapped = 0;
		size = length - 2;
		// odd2even pairs
		for (iter = 1; iter < size; iter += 2)
		{
			if (ptrArray[iter] > ptrArray[iter + 1])
			{
				swap2int(ptrArray+iter, ptrArray + iter + 1);
				swapped = 1;
			}
		}

		size = length - 1;
		// even2odd pairs
		for (iter = 0; iter < size; iter += 2)
		{
			if (ptrArray[iter] > ptrArray[iter + 1])
			{
				swap2int(ptrArray + iter, ptrArray + iter + 1);
				swapped = 1;
			}
		}

	} 
} 