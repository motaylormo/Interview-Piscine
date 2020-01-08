#include "header.h"
#include <stdlib.h>//qsort

/*---------------------------------------------------------
	Returns the integer description given the complete
			description contained in the s_info structure
  ---------------------------------------------------------*/
int		getDescription(struct s_info *info)
{
	int *arr = (int*)info;
	int d = 0;

	for (int i = 0; i < 7; ++i)
		d = (d * 10) + arr[i];
	return (d / 10);
}

/*----------------------------------------------------
	Sorts the array based on the integer description
			in an increasing order.
	You have to implement a radix sort.
  ----------------------------------------------------*/
#define DESCENDING(a,b)	((a) >= (b))
#define ASCENDING(a,b)	((a) <= (b))
#define ORDERED(a, b) ASCENDING(a->description, b->description)

static int	cmp(const void *a, const void *b)
{
	struct s_criminal *aa = *(struct s_criminal **)a;
	struct s_criminal *bb = *(struct s_criminal **)b;

    return (aa->description - bb->description);
}

void	sortCriminals(struct s_criminal **criminals, int n)
{
	qsort(criminals, n, sizeof(*criminals), cmp);
}

/*--------------------------------------------------
	Search through the sorted array for criminal
			corresponding to the given description.
	This must be done using binary search.
  --------------------------------------------------*/
static int binarySearch(int x, struct s_criminal **arr, int first, int last)
{
	if (last < first)
		return (-1);

	int mid = first + ((last - first) / 2);
	if (arr[mid]->description == x)
		return (mid);
	if (arr[mid]->description > x)
		return (binarySearch(x, arr, first, mid - 1));
	else
		return (binarySearch(x, arr, mid + 1, last));
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals,
											int n, struct s_info *info)
{
	int d = getDescription(info);
	int index = binarySearch(d, criminals, 0, n - 1);
	if (index == -1)
		return (NULL);

	while (index > 0 &&
		criminals[index - 1]->description == d)
		index--;

	int count = 0;
	while (index + count < n &&
		criminals[index + count]->description == d)
		count++;

	struct s_criminal **list = malloc(sizeof(struct s_criminal*) * count);
	list[count] = NULL;
	for (int i = 0; i < count; ++i)
	{
		list[i] = criminals[i + index];
	}
	return (list);
}