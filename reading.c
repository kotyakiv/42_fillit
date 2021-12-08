#include "fillit.h"
#include <stdio.h>

void ft_read_figure(char **map, t_pos *pos)
{
	int m;
	int top_r;
	int top_c;
	int	i;
	int	j;

	m = -1;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (map[i][j] == '#' && ++m == 0)
			{
				top_r = i;
				top_c = j;
			}
			else if (map[i][j] == '#' && m)
			{
				pos->coord->c = j - top_c;
				pos->coord->r = i - top_r;
			}
		}
	}
}

void	ft_free_map(char ***map)
{
	int i;

	i = 0;
	while (i < 4)
		free(map[i]);
}

void ft_read_tetrim_to_map(t_pos **pos, char *text)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open(text, O_RDONLY);
	if (fd < 0)
		exit(1);
	map = (char **)malloc(sizeof(char *));
	i = 0;
	j = 0;
	while (get_next_line(fd, &line))
	{
		if (i < 4)
			map[i++] = line;
		else
		{
			ft_read_figure(map, pos[j++]);
			ft_free_map(&map);
			free(line);
			i = 0;
		}
	}
}

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

void	ft_full_map(char map[20][20])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
			map[i][j] = '.';
	}	
}


int main(int argc, char **argv)
{
	t_pos 	*pos;
	char	map[20][20];
	int		n;

	pos = (t_pos *)malloc(sizeof(t_pos) * 4);
	ft_full_map(map);
	ft_read_tetrim_to_map(&pos, argv[1]);
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
			printf("%d,\t%d\n", pos[i].coord[j].r, pos[i].coord[j].c);
		printf("\n");
	}
	
	//ft_print_map(pos, map, 8);
	return (0);
}