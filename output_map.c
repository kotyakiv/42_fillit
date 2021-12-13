/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 05:24:30 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/13 16:42:10 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_tetr_to_map(t_map *map, t_pos pos)
{
	int	m;

	m = 0;
	map->map[pos.y][pos.x] = pos.value;
	while (m < 3)
	{
		map->map[pos.y + pos.coord[m].r][pos.x + pos.coord[m].c] = pos.value;
		++m;
	}
}

static void	ft_delete_tetr(t_map *map, t_pos *pos, t_coord c[26], int tetr)
{
	int	m;

	m = 0;
	map->map[pos->y][pos->x] = '.';
	while (m < 3)
	{
		map->map[pos->y + pos->coord[m].r][pos->x + pos->coord[m].c] = '.';
		++m;
	}
	pos->x = c[tetr].r;
	pos->y = c[tetr].c;
}

static	int	ft_check_pos(t_map map, t_pos *pos, int i, int j, t_coord c[26], int tetr)
{
	int	m;
	static int flag;

	m = 0;
	if (map.map[i][j] != '.')
		return (0);
	if (flag)
	{
		tetr++;
		c[tetr].r = i;
		c[tetr].c = j;
	}
	while (m < 3)
	{
		if ((j + pos->coord[m].c >= map.value || j + pos->coord[m].c < 0 \
				|| i + pos->coord[m].r >= map.value) || \
			map.map[i + pos->coord[m].r][j + pos->coord[m].c] != '.')
			return (0);
		else
			m++;
	}
	flag = 1;
	pos->x = j;
	pos->y = i;
	return (1);
}

static int	place_tetris(t_map *map, t_pos *pos, t_coord c[26], int i, int j, int tetr)
{
	if (ft_check_pos(*map, pos, i, j, c, tetr) == 1)
	{
		ft_tetr_to_map(map, *pos);
		return (1);
	}
	return (0);
}

int	change_map(t_map *map, t_pos pos[26], int tetr, int tetris, int *iter)
{
	int	x;
	int	y;
	static t_coord c[26];

	if (*iter >= 3000000)
		return (0);
	y = 0;
	if (tetr == tetris)
		return (1);
	while (y < map->value)
	{
		x = 0;
		while (x < map->value && tetr < tetris)
		{
			if (place_tetris(map, &pos[tetr], c, y, x, tetr))
			{
				if (change_map(map, pos, tetr + 1, tetris, iter))
					return (1);
				ft_delete_tetr(map, &pos[tetr], c, tetr);
				++(*iter);
			}
			x++;
		}
		y++;
	}
	return (0);
}
