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

int partition(int arr[], int indexS, int indexF)
{
	int pivot = arr[indexF];
	int indexPrePivot = indexS;
	int iter;

	for (iter = indexS; iter <= indexF - 1; ++iter)
	{
		if (arr[iter] <= pivot)
		{
			swap2int(arr + indexPrePivot, arr + iter);
			++indexPrePivot;
		}
	}
	swap2int(arr + indexPrePivot, arr + indexF);
	return indexPrePivot;
}


void quick_sort(int arr[], int indexS, int indexF)
{
	if (indexS < indexF)
	{
		int indexM = partition(arr, indexS, indexF);
		quick_sort(arr, indexS, indexM - 1);
		quick_sort(arr, indexM + 1, indexF);
	}
	return;
}