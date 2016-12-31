void swap2int(int *val1, int *val2)
{
	*val1 = (*val1) ^ (*val2);
	*val2 = (*val1) ^ (*val2);
	*val1 = (*val1) ^ (*val2);
}

int *cocktail_shaker_sort(int ptrArray[], const size_t size);
{
	int swapped;
	int iter, jiter;
	int jsize, isize;

	if (!size)
		return NULL;

	isize = size / 2;
	for (iter = 0; iter < isize; ++iter)
	{
		swapped = 0;
		jsize = size - iter - 1;
		for (jiter = iter; jiter < jsize; ++jiter)
		{
			if (ptrArray[jiter] > ptrArray[jiter + 1])
			{
				swap2int(ptrArray + jiter, ptrArray + jiter + 1);
				swapped = 1;
			}
		}

		for (jiter = size - 2 - iter; jiter > iter; --jiter)
		{
			if (ptrArray[jiter - 1] > ptrArray[jiter])
			{
				swap2int(ptrArray + jiter, ptrArray + jiter - 1);
				swapped = 1;
			}
		}

		if (!swapped)
			break;
	}
	return ptrArray;
}