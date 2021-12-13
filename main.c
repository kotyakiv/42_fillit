/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 05:19:36 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/13 16:42:28 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_pos	pos[26];
	t_map	*map;
	int		num;
	int		square;
	int iter;

	iter = 0;
	if (argc != 2)
	{
		write(2, "usage: ./fillit file_name\n", 26);
		return (1);
	}
	if (error_handling(argv[1]) == -1)
		return (1);
	num = ft_read_tetrim_from_map(pos, argv[1]);
	square = ft_smallest_square(num);
	map = ft_fill_map(square);
	while (!change_map(map, pos, 0, num, &iter))
	{
		iter = 0;
		square++;
		ft_freemap(map);
		map = ft_fill_map(square);
	}
	ft_print_map(*map);
	ft_freemap(map);
	return (0);
}
