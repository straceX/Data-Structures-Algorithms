int *sieve_of_eratosthenes(const int length,int *length_of_prime_array)
{
	int total = length - 2;
	int iter,jiter, pw;
	int *ptrPrime = NULL;
	int *ptrMap; 

	if ( !(ptrMap = (int *)( malloc(sizeof(int)*(length + 1)) ) ) )
		return NULL;
	if (!memset(ptrMap, 1, length))
		return NULL;


	for (pw = 2; pw*pw <= length; ++pw)
	{
		if (ptrMap[pw])
		{
			iter = pw * 2;
			for (; iter <= length; iter += pw)
			{
				if (ptrMap[iter])
				{
					ptrMap[iter] = 0;
					--total;
				}
				
			}
		}
	}

	ptrPrime = (int *)( malloc(sizeof(int)*total ));

	if (!ptrPrime)
		return NULL;

	*length_of_prime_array = total;

	for (jiter = 2, iter = 0; jiter <= length; ++jiter)
	{
		if (ptrMap[jiter])
			ptrPrime[iter++] = jiter;
	}

	free(ptrMap);

	return ptrPrime;
}
