#include "fillit.h"

void	ft_print_map(char **map, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}	
}

void ft_counter_init(t_coord *counter)
{
	counter->c = 0;
	counter->r = 0;
}

char **ft_map_alloc(int num)
{
	char **map;

	map = (char **)malloc(sizeof(char *) * num);
	if (!map)
		exit(1);
	for (int i = 0; i < num; i++)
	{
		map[i] = (char *)malloc(sizeof(char) * num);
		if (!map[i])
		{
			ft_free_map(&(map[i]), i + 1);
			free(map);
			exit(1);
		}
		ft_memset(map[i], '.', num);
	}
	return (map);
}