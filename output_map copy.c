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

static	int ft_check_pos(char map[20][20], t_pos pos[26], int i, int j, int tetr, int n)
{
	int m;

	m = 0;
	while (m < 3)
	{
		if ((j + pos[tetr].coord[m].c >= n || j + pos[tetr].coord[m].c < 0 \
				|| i + pos[tetr].coord[m].r >= n) || \
			map[i + pos[tetr].coord[m].r][j + pos[tetr].coord[m].c] != '.')
			return (0);
		else
			m++;
	}
	return (1);
}

void ft_erase_a(char map[20][20], int n, char a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (map[i][j] == a)
				map[i][j] = '.';
		}	
	}
}


int change_map(char map[20][20], t_pos pos[26], int n, int square)
{
	int m;
	int tetr;
	int i;
	int j;
	int flag;
	int mflag;
	char a;
	t_coord cor[26];
	int	pr;

	a = 'A';
	tetr = 0;
	i = 0;
	flag = 0;
	mflag = 0;
	while (i < square)
	{
		j = 0;
		while (j < square)
		{
			if (map[i][j] == '.')
			{
				if (tetr == n && pr)
				{
					tetr = pr;
					mflag = 1;
				}
				if (flag) //next pos after tetr
				{
					cor[tetr-1].c = j;
					cor[tetr-1].r = i;
					flag = 0;
				}
				m = 0;
				if (ft_check_pos(map, pos, i, j, tetr, square)) //if possible, put tetr
				{
					map[i][j] = a;
					while (m < 3)
					{
						map[i + pos[tetr].coord[m].r][j + pos[tetr].coord[m].c] = a;
						++m;
					}
					if (!mflag)
					{
						a++;
						tetr++;
						flag = 1;
					}
					else
						tetr = n;
				}
			}
			++j;
		}
		++i;

	if ( i == n && tetr != n)
	{
			ft_erase_a(map, square, --a);
			i = cor[tetr - 1].r;
			j = cor[tetr - 1].c;
			printf("YES\n");
			pr = tetr;
	}

	}

	


	for (size_t i = 0; i <= tetr; i++)
	{
		printf("%d,\t%d\n", cor[i].r, cor[i].c);
	}
	
	return (square);
}
