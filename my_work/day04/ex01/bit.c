#include <stdlib.h>//calloc
#include <string.h>//strcpy

#define BIT_N 4
#define VAL(x) (x - '0')

static char	*strNot(char *s)
{
	if (s[0] == '~')
	{
		for (int i = 0; i < BIT_N; ++i)
			s[i] = (s[i + 1] == '1') ? '0' : '1';
		s[BIT_N] = '\0';
	}
	return (s);
}

char	*getAnd(char *a, char *b)
{
	strNot(a);
	strNot(b);
	char *sum = calloc(6 + 1, sizeof(char));
	for (int i = 0; i < BIT_N; ++i)
		sum[i] = (VAL(a[i]) & VAL(b[i])) + '0';
	return (sum);
}

char	*getOr(char *a, char *b)
{
	char *sum = calloc(6 + 1, sizeof(char));
	strNot(a);
	strNot(b);
	for (int i = 0; i < BIT_N; ++i)
		sum[i] = (VAL(a[i]) | VAL(b[i])) + '0';
	return (sum);
}

int		toInt(char *bits)
{
	int not = 0;
	if (bits[0] == '~')
	{
		not = 1;
		bits++;
	}
	int n = 0;
	for (int i = 0; i < BIT_N; ++i)
	{
		n <<= 1;
		if (not)
			n |= !(bits[i] - '0');
		else
			n |= bits[i] - '0';
	}
	return (n);
}