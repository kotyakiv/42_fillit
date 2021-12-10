#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_pos 	pos[26];
	char	map[20][20];
	int		num;
	int		square;

	num = ft_read_tetrim_from_map(pos, argv[1]);
	ft_fill_map(map);
	square = ft_smallest_square(num);
	square = change_map(map, pos, num, square);
	ft_print_map(pos, map, square);

	return (0);
}