/*Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements 
where the number of elements (n) and the length of the range of possible key values (N) are 
approximately the same. It requires O(n + N) time. It is similar to counting sort, 
but differs in that it "moves items twice[1].
[1]: https://en.wikipedia.org/wiki/Pigeonhole_sort*/
int *pigeon_hole_sort(int *ptrArray,size_t size,int min, int max);