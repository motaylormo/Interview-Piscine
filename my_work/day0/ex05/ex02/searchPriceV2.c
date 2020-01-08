#include "header.h"
#include <string.h>//	strcmp

static int	half_recurse(struct s_art **arts, int start, int len, char *name)
{
	int ret;
	int half = len / 2;
	if ((ret = strcmp(arts[start + half]->name, name)) == 0)
		return (arts[start + half]->price);
	if (half > 0)
	{
		if (ret > 0)
			return (half_recurse(arts, start, len - half, name));
		if (ret < 0)
			return (half_recurse(arts, start + half, len - half, name));
	}
	return (-1);
}

int	searchPrice(struct s_art **arts, int n, char *name)
{
	return (half_recurse(arts, 0, n, name));
}