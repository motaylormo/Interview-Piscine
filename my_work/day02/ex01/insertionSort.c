#include "header.h"

#define DESCENDING(a,b)	((a) >= (b))
#define ASCENDING(a,b)	((a) <= (b))
#define ORDERED(a, b) DESCENDING(a->score, b->score)

static void	swap_nodes(struct s_player **a, struct s_player **b)
{
	struct s_player *tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertionSort(struct s_player **arr)
{
	for (int i = 1; arr[i]; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (ORDERED(arr[j - 1], arr[j]))
				break;
			swap_nodes(&arr[j], &arr[j - 1]);
		}
	}
}