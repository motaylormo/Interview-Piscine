#include <string.h>//memmove
#include <string.h>//memset

#define BIT_N 6
#define VAL(x) (x - '0')

char	*rightShift(char *bin, int k)
{
	if (k > BIT_N)
		return (NULL);
	memmove(bin + k, bin, BIT_N - k);
	memset(bin, bin[k], k);
	return (bin);
}

char	*leftShift(char *bin, int k)
{
	if (k > BIT_N)
		return (NULL);
	memmove(bin, bin + k, BIT_N - k);
	memset(bin + (BIT_N - k), '0', k);
	return (bin);
}

int		toInt(char *bits)
{
	int n = 0;
	for (int i = 1; i < BIT_N; ++i)
	{
		n <<= 1;
		n |= (bits[0]) ? !VAL(bits[i]) : VAL(bits[i]);
	}
	if (bits[0])
		n *= -1;
	return (n);
}