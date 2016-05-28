
int *BinarySearch(int *ptrArrayS, int *ptrArrayF,int val)
{
	int *ptrArrayM = ptrArrayS + (ptrArrayF - ptrArrayS) / 2;
	if (*ptrArrayM == val)
		return ptrArrayM;
	else if (ptrArrayM == ptrArrayS || ptrArrayM == ptrArrayF)
		return NULL;
	else
	{
		if (*ptrArrayM > val)
			BinarySearch(ptrArrayS, ptrArrayM - 1, val);
		else
			BinarySearch(ptrArrayM+1,ptrArrayF,val);
	}
}
