

int *comb_sort(int ptrArray[], size_t size)
{
	int gap = size;
	int swapped = 0;
	int iter, jiter;
	int tmp;

	if (!size)
		return NULL;
	

	while (gap > 1 || swapped)
	{
		gap = gap * 10 / 13;
		
		if (gap < 1)	gap = 1;
		if (gap == 9 || gap == 10)	gap = 11;
		swapped = 0;

		for (iter = 0, jiter = gap; jiter < size; ++iter, ++jiter)
		{
			if (ptrArray[iter]>ptrArray[jiter])
			{
				tmp = ptrArray[iter];
				ptrArray[iter] = ptrArray[jiter];
				ptrArray[jiter] = tmp;
				swapped = 1;
			}
		}
	}

	return ptrArray;

}
