
int		max(int* tab, unsigned int len)
{
	int max;

	while (len)
	{
		if (tab[len] > max)
		{
			max = tab[len];
		}
		len--;
	}
	return (max);
}
