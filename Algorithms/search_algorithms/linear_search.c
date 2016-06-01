
int linear_search(int ptrArray[],size_t length,int val)
{
	int iter;

	for (iter = 0; iter<length; ++iter)
	{
		if (ptrArray[iter] == val)
			return iter;
	}
	return -1;
}
