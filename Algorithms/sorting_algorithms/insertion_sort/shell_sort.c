int *shell_sort(int *ptrArray, int length)
{
	int iter, jiter, tmp, gap;

	if (!length || !ptrArray)
		return NULL;

	for (gap = length; gap; gap /= 2)
	{
		for (iter = gap; iter < length; ++iter)
		{
			tmp = ptrArray[iter];
			jiter = iter;
			for (; jiter >= gap && tmp < ptrArray[jiter - gap];)
			{
				ptrArray[jiter] = ptrArray[jiter - gap];
				jiter -= gap;
			}
				

			ptrArray[jiter] = tmp;
		}

	}
	return ptrArray;
}
