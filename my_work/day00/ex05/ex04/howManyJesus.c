#include <string.h>//	strlen, strchr, strncmp

int		native_search(char *str, char *pattern)
{
	int	tally = 0;
	int	pattern_len = strlen(pattern);
	while ((str = strchr(str, pattern[0])))
	{
		if (strncmp(str, pattern, pattern_len) == 0)
		{
			tally++;
			str += pattern_len;
		}
		else
			str++;
	}
	return (tally);
}

/*--------------------------------
	Rabin–Karp algorithm
  --------------------------------*/
size_t	hash(char *input, int len)
{
	size_t	h = 0xcbf29ce484222325;
	for (int i = 0; i < len; ++i)
	{
		h *= 0x100000001b3;
		h ^= input[i];
	}
	return (h);
}

int		rabin_karp(char *str, char *pattern)
{
	int	tally = 0;
	int	pattern_len = strlen(pattern);
	size_t pattern_hash = hash(pattern, pattern_len);
	for (int i = 0; str[i + pattern_len]; ++i)
	{
		if ((pattern_hash == hash(str + i, pattern_len)) &&
			(strncmp(str + i, pattern, pattern_len) == 0))
		{
			tally++;
		}
	}

	return (tally);
}

int	howManyJesus(char *str, char *pattern)
{
	if (!(str && pattern))
		return (0);

//	return (native_search(str, pattern));
	return (rabin_karp(str, pattern));
}