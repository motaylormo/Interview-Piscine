#include "header.h"

void	countSort(unsigned char *utensils, int n)
{
	int	table[0xFF] = {0};

	for (int i = 0; i < n; ++i)
		table[(int)utensils[i]]++;

	int ti = 0;
	for (int i = 0; i < n; ++i)
	{
		while (table[ti] == 0)
			ti++;
		utensils[i] = ti;
		table[ti]--;
	}
}