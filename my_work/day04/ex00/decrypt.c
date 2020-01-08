static void	add_one(char *s, int i)
{
	if (i < 0)
		return ;
	if (s[i] == '0')
		s[i] = '1';
	else if (s[i] == '1')
	{
		s[i] = '0';
		add_one(s, i - 1);
	}
}

char	*getSum(char *a, char *b)
{
	for (int i = 6 - 1; i >= 0; --i)
	{
		if (b[i] == '1')
			add_one(a, i);
	}
	return (a);
}

int		toInt(char *bits)
{
	int n = 0;
	for (int i = 0; i < 6; ++i)
	{
		n <<= 1;
		n |= bits[i] - '0';
	}
	return (n);
}