#include <iostream>

int	strlen(char *str)
{
	int	i = 0;

	while (*str++)
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int		i = 0;
	int		j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (++i < ac)
	{
		j = -1;
		while (++j < strlen(av[i]))
		{
			if ('a' <= av[i][j] && av[i][j] <= 'z')
				std::cout << static_cast<char>(av[i][j] - 32);
			else
				std::cout << av[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}