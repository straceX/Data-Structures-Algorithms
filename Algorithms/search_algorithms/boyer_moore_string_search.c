#include "boyer_moore_string_search.h"

int get_max(int a, int b) { return (a > b) ? a : b; }

void setGoodSuffixTable(char *str, int size, int bad_suffix_table[])
{

}
void setBadSuffixTable(const char searched_word[], int size, int bad_suffix_table[])
{
	int iter;
	for (iter = 0; iter < COUNT_OF_CHAR; ++iter)
		bad_suffix_table[iter] = -1;

	for (iter = 0; iter < size; ++iter)
		bad_suffix_table[(int) searched_word[iter]] = iter;
}

void BoyerMooreStringSearch(const char *source, const char *searched_word)
{
	int searched_wordternlen	= strlen(searched_word);
	int sourcelen	= strlen(source);
	int bad_suffix_table[COUNT_OF_CHAR];
	int riter = 0;
	int total_shift = 0;  
	int possible_max_shift = sourcelen - searched_wordternlen;
	int localjump = 0;
	
	setBadSuffixTable(searched_word, searched_wordternlen, bad_suffix_table);

	while (total_shift <= possible_max_shift)
	{
		riter = searched_wordternlen - 1;
		while (riter >= 0 && searched_word[riter] == source[total_shift + riter])
			--riter;

		if (riter < 0)
		{
			printf("source[ %d ] is start point of searched word\n", total_shift);
			localjump = searched_wordternlen - bad_suffix_table[source[total_shift + searched_wordternlen]];
			total_shift += (total_shift + searched_wordternlen < sourcelen) ? localjump : 1;
		}
		else {
			total_shift += get_max(1, riter - bad_suffix_table[source[total_shift + riter]]);
		}
	}
}