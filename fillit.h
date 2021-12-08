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

#endif