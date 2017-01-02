int *pigeon_hole_sort(int *ptrArray,size_t size,int min, int max)
{
	int *low = ptrArray;
	int *high = ptrArray + size - 1;
	int count = 0;
	int *iter = NULL;	
	const int hole_size = max - min + 1;
	
	if (!size)
		return NULL;
	
	if (hole_size < 1)
		return NULL;

	int *pholes = (int *)calloc(hole_size,sizeof(int));

	if (!pholes)
		return NULL;

	/*Filling the pigeonholes*/
	for (iter = low; iter <= high; ++iter)
		pholes[*iter - min] += 1;

	/*Filling the array*/
	for (iter = low, count = 0; count < hole_size; ++count)
		while (pholes[count]-- > 0)
			*iter++ = count + min;
	
	if (count != size)
		return NULL;

	return ptrArray;
}