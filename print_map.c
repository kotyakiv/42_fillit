#include "fillit.h"

void	ft_print_map(t_pos pos[26], char map[20][20], int n)
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

void	ft_fill_map(char map[20][20])
{
	ft_memset(*map, '.', 400);
}
