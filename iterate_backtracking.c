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

void	ft_erase(char ***map, t_pos *pos, int square, int i, int j, char a)
{
	for (size_t i = 0; i < square; i++)
	{
		for (size_t j = 0; j < square; j++)
		{
			if ((*map)[i][j] == a)
				(*map)[i][j] = '.';
		}
	}
}

static int if_in_stack(int stack[26], int tetr)
{
	int i;
	
	i = 0;
	while (i < 26 && stack[i] != -1)
	{	
		if (stack[i] == tetr)
			return (1);
		i++;
	}
	return (0);
}

static int if_stack_is_full(int stack[26], int tetris)
{
	int i;

	i = 0;
	while (i < 26 && stack[i] != -1)
		++i;
	if (tetris == i)
		return (1);
	return (0);
}

static void print_stack(int stack[26])
{
	int i;

	i = 0;
	while (stack[i] != -1)
	{
		printf("%d ", stack[i]);
		++i;
	}
	printf("\n");
}

static void fill_stack(int stack[26])
{
	int i;

	i = 0;
	while (i < 26)
	{
		stack[i] = -1;
		i++;
	}
}

int change_map(char **map, t_pos *pos, int tetris, int square)
{
	int	i;
	int	j;
	int stack[26];
	int tetr;
	int k;
	char a;

	fill_stack(stack);
	tetr = 0;
	k = 0;
	while (1)
	{
	    
		i = -1;
		while (++i < square)
		{
			j = -1;
			while (++j < square)
			{
				if (map[i][j] == '.')
				{
						if (!if_in_stack(stack, tetr) && ft_check_pos(map, pos, i, j, tetr, square))
						{
							a = 'A' + tetr;
							ft_tetr_to_map(&map, pos, a, tetr, i, j);
							stack[k] = tetr;
							k++;
							tetr = 0;
							i = -1;
							j = -1;
							break;
						}
						
				}
			}
		}
		tetr++;
		if (stack[0] == tetris)
			return (0);
		if (if_stack_is_full(stack, tetris))
	    	return (1);
		while (tetr == tetris)
		{
			tetr = stack[--k];
			a = 'A' + tetr;
			ft_erase(&map, pos, square, i, j, a);
			stack[k] = -1;
			tetr++;
		}
	}
	return (0);
}
