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

int *selection_sort(int ptrArray[], size_t size)
{
	int iterA,iterB,iter;
	int *ptrSmallest;

	for (iterA = 0; iterA <size - 1; ++iterA)
	{
		ptrSmallest = ptrArray + iterA;

		for (iterB = iterA+1; iterB<size; ++iterB)
		{
			if (ptrArray[iterB] < (*ptrSmallest))
				ptrSmallest = ptrArray + iterB;
		}
		swap2int(ptrArray + iterA, ptrSmallest);
		
	}
	return ptrArray;

}