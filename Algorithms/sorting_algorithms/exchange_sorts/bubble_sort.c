void swap2int(int *val1,int *val2)
{
    *val1 = (*val1) ^ (*val2);
    *val2 = (*val1) ^ (*val2);
    *val1 = (*val1) ^ (*val2);
}

int *bubble_sort(int *ptrArray, size_t size)
{
	int iterA,iterB;
	int isswap;

	for (iterA = 0; iterA < size - 1; ++iterA)
	{
		isswap = 0;
		for (iterB = 0; iterB < size - 1 - iterA; ++iterB)
		{
			if (ptrArray[iterB]>ptrArray[iterB + 1])
			{
				swap2int(ptrArray+iterB, ptrArray+iterB + 1);
				isswap = 1;
			}
		}
		if (!isswap)
			break;
	}
	return ptrArray;
}