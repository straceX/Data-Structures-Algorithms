int interpolation_search(int ptrArray[], size_t length, int val) 
{

	int mid;
	int bottom = 0;
	int top = length - 1;

	if (!length)
		return -1;
	
	if (!top)
	{
		if (ptrArray[bottom] == val)
			return bottom;
		else
			return -1;
	}
	
	do
	{
		mid = bottom + ((top - bottom) * (val - ptrArray[bottom]) / (ptrArray[top] - ptrArray[bottom]));

		if (val == ptrArray[mid])
			return mid;
		else if (val < ptrArray[mid])
			top = mid - 1;
		else
			bottom = mid + 1;
	
	} while (bottom <= top);

	return -1;
}