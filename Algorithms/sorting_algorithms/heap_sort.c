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
void heapify(int ptrArray[], size_t size, size_t rIndex)
{
	int largestIndex = rIndex;  /* Initialize largest as root */

	int left_leaf  = 2 * rIndex + 1;  /* left leaf Index in Array */
	int right_leaf = 2 * rIndex + 2;  /* right leaf Index in Array */


	if ( (ptrArray[left_leaf] > ptrArray[largestIndex]) && (left_leaf < size) )
		largestIndex = left_leaf;

	if ((ptrArray[right_leaf] > ptrArray[largestIndex]) && (right_leaf < size) )
		largestIndex = right_leaf;

	if (largestIndex != rIndex)
	{
		swap2int(ptrArray + rIndex, ptrArray + largestIndex);

		heapify(ptrArray, size, largestIndex);
	}

	return;

}
int *heap_sort(int ptrArray[], size_t size)
{
	int treeDepthIter;

	for (treeDepthIter = size / 2 - 1; 0 <= treeDepthIter; --treeDepthIter)	
		heapify(ptrArray, size, treeDepthIter);

	for (treeDepthIter = size - 1; treeDepthIter >= 0; --treeDepthIter)
	{
		swap2int(ptrArray, ptrArray + treeDepthIter);

		heapify(ptrArray, treeDepthIter, 0);
	}
	return ptrArray;
}
