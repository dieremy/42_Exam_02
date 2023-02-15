#include <unistd.h>

int check_pos(char *s, int i, int pos)
{
	int	j;

	j = 0;
	while (j < pos)
	{
		if (s[j] == i)
			return (0);
		j++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					if (check_pos(av[1], av[1][i], i))
					{
						write(1, &av[1][i], 1);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
