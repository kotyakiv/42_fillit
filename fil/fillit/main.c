#include "fillit.h"



int main(int argc, char **argv)
{
	t_pos 	pos[26];
	char	**map;
	int		num;
	int		square;
	
	if (error_handling(argv[1]) == -1)
	{
		printf("error\n");
		return (-1);
	}
	num = ft_read_tetrim_from_map(pos, argv[1]);
	map = ft_map_alloc(num);
	square = ft_smallest_square(num);
	while (!change_map(map, pos, num, square, 0))
	{
		++square;
		ft_free_map(&map, num);
		free(map);
		map = ft_map_alloc(num);
	}
	ft_print_map(map, square);
	ft_free_map(&map, num);
	free(map);
	free(pos);
	return (0);
}
