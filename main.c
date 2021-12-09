#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_pos 	pos[26];
	char	map[20][20];
	int		num;

	num = ft_read_tetrim_from_map(pos, argv[1]);

	ft_fill_map(map);
	change_map(map, pos, 6);
	ft_print_map(pos, map, 6);

	return (0);
}