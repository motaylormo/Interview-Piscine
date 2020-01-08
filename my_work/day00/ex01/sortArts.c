#include "header.h"
#include <stdlib.h>//	qsort
#include <string.h>//	strcmp

/*
**	artCmp is to be used with qsort from the library
*/
int        artCmp(const void *a, const void *b)
{
    struct s_art *aa = *(struct s_art **)a;
    struct s_art *bb = *(struct s_art **)b;

    if (aa == 0 || bb == 0)
        return (0);
    return (strcmp(aa->name, bb->name));
}

/*
**	swapTwo and selectionSort are part of the selection sort I wrote
*/
void	swapTwo(struct s_art *a, struct s_art *b)
{
	struct s_art tmp = *a;
	*a = *b;
	*b = tmp;
}

void	selectionSort(struct s_art **arr, int size)
{
	int	min;

	for (int i = 0; i < size; ++i)
	{
		min = i;
		for (int j = i; j < size; ++j)
		{
			if (strcmp(arr[min]->name, arr[j]->name) > 0)
				min = j;
		}
		swapTwo(arr[i], arr[min]);
	}
}

void	sortArts(struct s_art **arts)
{
	int	size = 0;
	while (arts[size])
		size++;

//	selectionSort(arts, size);
	qsort(arts, size, sizeof(*arts), artCmp);
}