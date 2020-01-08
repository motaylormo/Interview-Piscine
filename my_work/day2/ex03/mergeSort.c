#include "header.h"
#include <string.h>//	memcpy

#define DESCENDING(a,b)	((a) >= (b))
#define ASCENDING(a,b)	((a) <= (b))
#define ORDERED(a, b) DESCENDING(a->score, b->score)

static void	merge(struct s_player **arr, int first, int mid, int last)
{
	int tmp_size = last - first + 1;
	struct s_player *tmp[tmp_size];

	int p1 = first;
	int p2 = mid + 1;
	for (int i = 0; i < tmp_size; ++i)
	{
		//	checks if first part comes to its end
		if (p1 > mid)
			tmp[i] = arr[p2++];
		//	checks if second part comes to its end
		else if (p2 > last)
			tmp[i] = arr[p1++];
		//	checks which part has elemnt that fits order
		else
			tmp[i] = (ORDERED(arr[p1], arr[p2])) ? arr[p1++] : arr[p2++];
	}

	memcpy(arr + first, tmp, sizeof(struct s_player*) * tmp_size);
}

static void	inner_mergesort(struct s_player **arr, int first, int last)
{
	if (!(first < last))
		return ;

	int mid = (first + last) / 2;// defines the current array in 2 parts
	inner_mergesort(arr, first, mid);// sort the 1st part of array
	inner_mergesort(arr, mid + 1, last);// sort the 2nd part of array

	// merge the both parts by comparing elements of both the parts.
	merge(arr, first, mid, last);
}

struct s_player	**mergeSort(struct s_player **players)
{
	int len = 0;
	while (players[len])
		len++;

	inner_mergesort(players, 0, len - 1);
	return (players);
}
