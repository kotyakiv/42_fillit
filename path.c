#include "fillit.h"
#include <stdio.h>

typedef	struct	s_move
{
	int		row;
	int		col;
}				t_move;

typedef	struct	s_pos
{
	int		max_row;
	int		max_col;
	t_move	move[3];
}				t_pos;

void print_map(char map[][4])
{
	for(int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}

}

void read_figure(char **map, t_pos *pos)
{
	int m = -1;

	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
		{
			if (map[i][j] == '#')
			{
				if (m == -1)
				{
					pos->max_row = i;
					pos->max_col = j;
					++m;
				}
				else
				{
					pos->move[m].col = pos->max_col - j;
					pos->move[m].row = i - pos->max_row;
					++m;
				}
			}
		}
}

void input_new_map(char new_map[][4])
{
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			new_map[i][j] = '.';
}

void change_map(char map[][4], t_pos pos)
{
	int m;
	int flag;

	for (int i = 0; i < 3; ++i)
		printf("%d, %d\n", pos.move[i].row, pos.move[i].col);

	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
		{
			flag = 1;
			if (map[i][j] == '.')
			{
				map[i][j] = 'A';
				m = 0;
				while (m < 3)
				{
					if (j + pos.move[m].col > 3 || j + pos.move[m].col < 0 \
						|| i + pos.move[m].row > 3)
						{
							flag = 0;
							map[i][j] = '.';
						}
					++m;
				}
				m = 0;
				while (flag && m < 3)
				{
					map[i + pos.move[m].row][j + pos.move[m].col] = 'A';
					++m;
					if (m == 3)
						return ;
				}
			}
		}
}

int main()
{
	char	**map;
	char new_map[4][4];
	char	*line;
	int		fd;
	int		i;
	t_pos	pos;

	map = (char **)malloc(sizeof(char *) * 4);
	fd = open("map", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		map[i] = line;
		++i;
	}
	read_figure(map, &pos);
	input_new_map(new_map);
	change_map(new_map, pos);
	print_map(new_map);

	return 0;
}
