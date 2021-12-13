#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

typedef	struct	s_coord
{
	int	r;
	int	c;
}				t_coord;

typedef	struct	s_pos
{
	t_coord	coord[3];
}				t_pos;

int		delete_data(char **line, int size);

int		ft_read_tetrim_from_map(t_pos pos[26], char *file_name);
char	**ft_read_from_file(char *file_name);
void	ft_free_map(char ***map, int num);
void	ft_read_coord(char **map, t_pos pos[26], int n);
int		ft_smallest_square(int num);

int 	ft_check_pos(char **map, t_pos pos[26], int i, int j, int k, int n);
void	ft_tetr_to_map(char ***map, t_pos pos[26], char a, int tetr, int i, int j);
void	ft_erase(char ***map, t_pos pos[26], int tetr, int i, int j);
int		change_map(char **map, t_pos pos[26], int n, int square, int tetr);

void	ft_print_map(char **map, int n);
void 	ft_counter_init(t_coord *counter);
char 	**ft_map_alloc(int num);

#endif
