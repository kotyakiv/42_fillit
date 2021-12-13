#include "fillit.h"
#include <stdio.h>

int ft_check_pos(char **map, t_pos *pos, int i, int j, int k, int n)
{
	int flag;
	int m;

	m = 0;
	while (m < 3)
	{
		if (j + pos[k].coord[m].c >= n || j + pos[k].coord[m].c < 0 \
				|| i + pos[k].coord[m].r >= n)
			return (0);
		else if (map[i + pos[k].coord[m].r][j + pos[k].coord[m].c] != '.')
			return (0);
		else
			m++;
	}
	return (1);
}

void	ft_tetr_to_map(char ***map, t_pos *pos, char a, int tetr, int i, int j)
{
	int m;

	m = 0;
	(*map)[i][j] = a;
	while (m < 3)
	{
		(*map)[i + pos[tetr].coord[m].r][j + pos[tetr].coord[m].c] = a;
		++m;
	}
}

void	ft_erase(char ***map, t_pos *pos, int tetr, int i, int j)
{
	int m;

	m = 0;
	(*map)[i][j] = '.';
	while (m < 3)
	{
		(*map)[i + pos[tetr].coord[m].r][j + pos[tetr].coord[m].c] = '.';
		++m;
	}
}

int change_map(char **map, t_pos *pos, int n, int square, int tetr)
{
	int i;
	int j;
	char a;

	a = 'A' + tetr;
	i = -1;
	while (++i < square)
	{
		j = -1;
		while (++j < square && tetr < n)
		{
			if (map[i][j] == '.')
			{
				if (ft_check_pos(map, pos, i, j, tetr, square))
				{
					ft_tetr_to_map(&map, pos, a, tetr, i, j);
					if (change_map(map, pos, n, square, tetr + 1))
						return (1);
					ft_erase(&map, pos, tetr, i, j);
				}
			}
		}
	}
	if (tetr == n)
		return (1);
	return (0);
}
