#include "header.h"

#define DESCENDING(a,b)	((a) >= (b))
#define ASCENDING(a,b)	((a) <= (b))
#define ORDERED(a, b) ASCENDING(a->size, b->size)// "in increasing order"

static void	swap_values(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//stone is a pointer to the first
void	sortStones(struct s_stone **stone)
{
	int swapped;

	while (1)
	{
		swapped = 0;
		for (struct s_stone	*n = *stone; n && n->next; n = n->next)
		{
			if (!ORDERED(n, n->next))
			{
				swap_values(&(n->size), &(n->next->size));
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}