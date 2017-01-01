/*Bucket sort, or bin sort, is a sorting algorithm that works 
by distributing the elements of an array into a number of buckets. 
Each bucket is then sorted individually, either using a different sorting algorithm, 
or by recursively applying the bucket sorting algorithm[1].
[1]: https://en.wikipedia.org/wiki/Bucket_sort */

void bucket_sort(int ptrArray[], const size_t size, const int minval, const int maxval, const int bucket_size);