#include "fillit.h"
#include <stdio.h>

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

static	int ft_check_pos(char map[20][20], t_pos pos[26], int i, int j, int k, int n)
{
	int flag;
	int m;

	m = 0;
	while (m < 3)
	{
		if ((j + pos[k].coord[m].c >= n || j + pos[k].coord[m].c < 0 \
				|| i + pos[k].coord[m].r >= n) || \
			map[i + pos[k].coord[m].r][j + pos[k].coord[m].c] != '.')
			return (0);
		else
			m++;
	}
	return (1);
}

void	ft_tetr_to_map(char map[20][20], t_pos pos[26], char *a, int *tetr, int i, int j)
{
	int m;

	m = 0;
	map[i][j] = *a;
	while (m < 3)
	{
		map[i + pos[*tetr].coord[m].r][j + pos[*tetr].coord[m].c] = *a;
		++m;
	}
	(*a)++;
	(*tetr)++;
}


int change_map(char map[20][20], t_pos pos[26], int n, int square)
{
	int m;
	int tetr;
	int i;
	int j;
	char a;

	a = 'A';
	tetr = 0;
	i = -1;
	while (++i < square)
	{
		j = -1;
		while (++j < square && tetr < n)
		{
			if (map[i][j] == '.')
				if (ft_check_pos(map, pos, i, j, tetr, square))
					ft_tetr_to_map(map, pos, &a, &tetr, i, j);
		}
	}
	return (square);
}
