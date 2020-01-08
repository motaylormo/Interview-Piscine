#include "header.h"

static int binarySearch(int x, int *arr, int first, int last)
{
	if (last < first)
		return (-1);

	int mid = first + ((last - first) / 2);
	if (arr[mid] == x)
		return (mid);
	if (arr[mid] > x)
		return (binarySearch(x, arr, first, mid - 1));
	else
		return (binarySearch(x, arr, mid + 1, last));
}

static int	account_for_shift(int x, int *arr, int first, int last)
{
	if (last < first)
		return (-1);
	int ret;
	int mid = first + ((last - first) / 2);
	if (arr[mid] == x)
		return (mid);
	if (arr[first] < arr[mid])
	{
		if ((ret = binarySearch(x, arr, first, mid - 1)) != -1)
			return (ret);
		return (account_for_shift(x, arr, mid + 1, last));
	}
	else
	{
		if ((ret = binarySearch(x, arr, mid + 1, last)) != -1)
			return (ret);
		return (account_for_shift(x, arr, first, mid - 1));
	}
}

int	searchShifted(int *rocks, int length, int value)
{
	return (account_for_shift(value, rocks, 0, length - 1));
}