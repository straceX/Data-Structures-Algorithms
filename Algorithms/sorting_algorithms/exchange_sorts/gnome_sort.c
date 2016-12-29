#include "gnome_sort.h"

int *gnome_sort(int ptrArray[], size_t size)
{
	int tmp;
	size_t iter		= 1;
	size_t jiter	= 2;

	if (!size)
		return NULL;

	while (iter < size)
	{
		if (ptrArray[iter - 1] > ptrArray[iter])
		{
			tmp = ptrArray[iter];
			ptrArray[iter] = ptrArray[iter - 1];
			ptrArray[iter - 1] = tmp;

			if (--iter)
				continue;
				
		}
		iter = jiter++;
	}
	return ptrArray;

}