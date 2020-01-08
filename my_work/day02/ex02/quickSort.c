#include "header.h"

#define DESCENDING(a,b)	((a) >= (b))
#define ASCENDING(a,b)	((a) <= (b))
#define ORDERED(a, b) DESCENDING(a->score, b->score)

#define CHOOSE_PIVOT (first)
//#define CHOOSE_PIVOT ((first + last) / 2)

static void	swap_nodes(struct s_player **a, struct s_player **b)
{
	struct s_player *tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	inner_quicksort(struct s_player **arr, int first, int last)
{
	if (!(first < last))
		return ;

	int pivot = CHOOSE_PIVOT;
	int lt = first;
	int rt = last;
	while (lt < rt)
	{
		while ((lt <= last) && ORDERED(arr[lt], arr[pivot]))
			lt++;
		while ((rt >= first) && !ORDERED(arr[rt], arr[pivot]))
			rt--;
		if (lt < rt)
			swap_nodes(&arr[lt], &arr[rt]);
	}
	swap_nodes(&arr[pivot], &arr[rt]);

	inner_quicksort(arr, first, rt - 1);
	inner_quicksort(arr, rt + 1, last);
}

void	quickSort(struct s_player **players)
{
	int len = 0;
	while (players[len])
		len++;

	inner_quicksort(players, 0, len - 1);
}
