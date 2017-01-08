/*In mathematics, the sieve of Eratosthenes (Ancient Greek: κόσκινον Ἐρατοσθένους, kóskinon Eratosthénous),
one of a number of prime number sieves, is a simple, ancient algorithm for finding all prime numbers up 
to any given limit. It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, 
starting with the multiples of 2 [1].
[1] : https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes */
int *sieve_of_eratosthenes(const int length,int *length_of_prime_array);