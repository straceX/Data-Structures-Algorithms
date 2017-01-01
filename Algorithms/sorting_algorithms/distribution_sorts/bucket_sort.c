typedef struct Bucket
{
	int count;
	int* values;
} bucket;

int compare_int(const void* first, const void* second)
{
	int a = *((int*)first);
	int b = *((int*)second);

	if (a == b)
		return 0;
	else if (a < b)
		return -1;
	else
		return 1;
}

void bucket_sort(int ptrArray[], const size_t size, const int minval, const int maxval, const int bucket_size)
{
	bucket *buckets;
	int iter, jiter, kiter;
	int i = 0, gap = 0;
	int tmpSize = 0;

	buckets = (bucket*)(malloc(sizeof(bucket)*bucket_size));

	if (!buckets)
		return NULL;
	if (!bucket_size || !size)
		return NULL;
	
	for (iter = 0; iter < bucket_size; ++iter)
	{
		buckets[iter].count = 0;
		buckets[iter].values = (int*)malloc(sizeof(int)* size); /* Can I optimize these line?*/
	}

	gap = (maxval - minval + 1) / bucket_size;

	for (iter = 0; iter < size; ++iter)
	{
		/*length_of_range = (max - min + 1)*/
		/* n =  (number - min) / length_of_range + 1 */
		i = (ptrArray[iter] - minval) / gap;
		i = i == bucket_size ? --i : i;
		buckets[i].values[buckets[i].count++] = ptrArray[iter];
	}

	for (kiter = 0, iter = 0; iter < bucket_size; ++iter)
	{
		if (!buckets[iter].count)
			continue;
		
		tmpSize = buckets[iter].count;
		qsort(buckets[iter].values,tmpSize, sizeof(int), &compare_int);
		
		for (jiter = 0; jiter < tmpSize; ++jiter)
		{
			ptrArray[kiter + jiter] = buckets[iter].values[jiter];
		}

		kiter += tmpSize;
		free(buckets[iter].values);
	}
}