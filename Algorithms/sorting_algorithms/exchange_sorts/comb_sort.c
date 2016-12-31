void swap2int(int *val1,int *val2)
{
    *val1 = (*val1) ^ (*val2);
    *val2 = (*val1) ^ (*val2);
    *val1 = (*val1) ^ (*val2);
}


int *comb_sort(int ptrArray[], const size_t size)
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
				swap2int(ptrArray+iter,ptrArray+jiter);
				swapped = 1;
			}
		}
	}

	return ptrArray;

}
