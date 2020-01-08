#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	run_test(char *s1, char *s2, char c)
{
	char *a = strdup(s1);
	char *b = strdup(s2);

	printf("%s (%2d) & %s (%2d) = ", a, toInt(a), b, toInt(b));
	char *res = (c == '&') ? getAnd(a, b) : getOr(a, b);
	printf("%s (%2d)\n", res, toInt(res));
}

int main(void)
{
	char *s[][2] = {
		{"0010", "0000"},
		{"0010", "1111"},
		{"0010", "0010"},
		{"0010", "1101"},
	};

	for (int i = 0; i < 4; ++i)
		run_test(s[i][0], s[i][1], '&');
	run_test("0010", "~1101", '|');
	printf("\n");

	for (int i = 0; i < 4; ++i)
		run_test(s[i][0], s[i][1], '|');
	run_test("~0010", "1101", '|');

	return (0);
}



// Function used for the test
// Don't go further :)

int checkBinary(char *str)
{
	int i = 0;

	if (str[i] && str[i] == '~')
		i++;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1')
			return (0);
		i++;
	}
	if (i == 4 || i == 5)
		return (1);
	return (0);
}