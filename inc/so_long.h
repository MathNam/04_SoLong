/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:01:58 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/06 18:43:45 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define IMG_W 64
# define IMG_H 64
# define K_ESC 0xff1b
# define K_W XK_w
# define K_A XK_a
# define K_S XK_s
# define K_D XK_d
# define ALIVE 1
# define DEAD 0

enum e_config_error
{
	E_SUCCESS = 0,
	E_STD,
	E_NOMSG,
	E_ARG,
	E_EXT,
	E_FILE,
	E_MEM,
	E_GNL,
	E_DIM,
	E_EMPTY,
	E_WALL,
	E_TYPE,
	E_CNT,
	E_PATH,
};

typedef enum e_config_error	t_error;

typedef struct s_sprites
{
	void	*f[3];
	void	*s[8];
	void	*w[3];
	void	*io[3];
	void	*c[2];
	void	*p[1];
}	t_sprites;

typedef struct s_point
{
	char	type;
	void	*img;
	int		acc;
	int		x;
	int		y;
}	t_point;

typedef struct s_player
{
	int		dir;
	int		x;
	int		y;
}	t_player;

typedef struct s_count
{
	int	p;
	int	e;
	int	c;
}	t_count;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	t_point		**map;
	t_player	p1;
	int			end;
	t_sprites	spt;
	t_count		cnt;
	int			mv_cnt;
}	t_game;

/*---Error description functions---*/
//Print error description in terminal
void	msg_error(int err_id, char *item);
//Free structure and exit program with message error
void	exit_error(int err_id, char *item, t_game *data);

void	free_map(t_point **map, int height);
void	free_game(t_game *data);

void	print_map(t_game *data);

t_point	*find_point(t_game *data, char c);
void	move_up(t_game *data);
void	move_down(t_game *data);
void	move_left(t_game *data);
void	move_right(t_game *data);

void	set_map_dim(t_game *data, char *file);
t_point	**init_map(t_game	*data);
void	set_point(t_point *pt, char type, int x, int y);
void	set_map(t_game *data, char *file);
void	xpm_sea_to_img(t_game *data);
void	xpm_map_to_img(t_game *data);
void	xpm_player(t_game *data);
void	sea_tile(t_game *data);
void	gnd_tile(t_game *data);
void	generate_map(t_game *data);
t_game	*init_game(char *file);

int		wall_check(t_game *data);
int		type_count_check(t_game *data);
void	flood(t_point **map, t_point *pt);
int		path_check(t_game *data);
int		map_error(t_game *data);

void	file_type_check(char *file);

//Test
void	render_map(t_game *data);
int		exit_game(t_game *data);
void	play(t_game *data);

#endif