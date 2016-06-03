
int *ptrTmpArray = NULL;

void merging(int ptrArray[], int indexS, int indexM, int indexF)
{
	int pivotL, pivotH, iter;
	pivotL = indexS;
	pivotH = indexM + 1;
	

	for (iter = indexS; pivotL <= indexM && pivotH <= indexF; ++iter)
	{
		if (ptrArray[pivotL] <= ptrArray[pivotH])
			ptrTmpArray[iter] = ptrArray[pivotL++];
		else
			ptrTmpArray[iter] = ptrArray[pivotH++];
	}

	while (pivotL <= indexM)
		ptrTmpArray[iter++] = ptrArray[pivotL++];

	while (pivotH <= indexF)
		ptrTmpArray[iter++] = ptrArray[pivotH++];

	for (iter = indexS; iter <= indexF; ++iter)
		ptrArray[iter] = ptrTmpArray[iter];

}

void mergesort(int ptrArray[], int indexS, int indexF)
{
	int indexM;
    if (indexS < indexF)
    {     
		indexM = indexS + (indexF - indexS) / 2;

		mergesort(ptrArray, indexS, indexM);
		mergesort(ptrArray, indexM + 1, indexF);

		merging(ptrArray, indexS, indexM, indexF);
    }
}

int *merge_sort(int ptrArray[], int indexS, int indexF)
{
	size_t size = indexF - indexS + 1;
	if (!(ptrTmpArray = (int *)(malloc(sizeof(int)*size))))
		return NULL;
	else
		mergesort(ptrArray, indexS, indexF);
		
}