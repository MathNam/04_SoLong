/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:01:58 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/13 17:08:48 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <X11/keysym.h>
# include <X11/X.h>

/* Image dimension */
# define IMG_W 64
# define IMG_H 64

/* Key code */
# define K_ESC 0xff1b
# define K_W XK_w
# define K_A XK_a
# define K_S XK_s
# define K_D XK_d
# define ALIVE 1

/*-----Path to image assets-----*/
/*--        Map tiles        ---*/
// Sea tiles
# define SEA_T "assets/map/sea/top.xpm"
# define SEA_B "assets/map/sea/bottom.xpm"
# define SEA_L "assets/map/sea/left.xpm"
# define SEA_R "assets/map/sea/right.xpm"
# define SEA_TL "assets/map/sea/top_left.xpm"
# define SEA_TR "assets/map/sea/top_right.xpm"
# define SEA_BL "assets/map/sea/bottom_left.xpm"
# define SEA_BR "assets/map/sea/bottom_right.xpm"
// Entry | Exit tiles
# define ENTRY "assets/map/io/entry.xpm"
# define EXIT_0 "assets/map/io/exit_closed.xpm"
# define EXIT_1 "assets/map/io/exit_open.xpm"
// Ground tiles
# define GND_0 "assets/map/floor/std_0.xpm"
# define GND_1 "assets/map/floor/std_1.xpm"
# define GND_2 "assets/map/floor/std_2.xpm"
// Collectible tiles
# define LOOT_0 "assets/map/collect/closed.xpm"
# define LOOT_1 "assets/map/collect/open.xpm"
// Obstacles tiles
# define WALL_0 "assets/map/wall/hole.xpm"
# define WALL_1 "assets/map/wall/mountain.xpm"
# define WALL_2 "assets/map/wall/stone.xpm"
/*--      Player sprites     ---*/
// Idle
# define IDLE_L0 "assets/player/idle/idle_left_0.xpm"
# define IDLE_L1 "assets/player/idle/idle_left_1.xpm"
# define IDLE_L2 "assets/player/idle/idle_left_2.xpm"
# define IDLE_L3 "assets/player/idle/idle_left_3.xpm"
# define IDLE_L4 "assets/player/idle/idle_left_4.xpm"
# define IDLE_R0 "assets/player/idle/idle_right_0.xpm"
# define IDLE_R1 "assets/player/idle/idle_right_1.xpm"
# define IDLE_R2 "assets/player/idle/idle_right_2.xpm"
# define IDLE_R3 "assets/player/idle/idle_right_3.xpm"
# define IDLE_R4 "assets/player/idle/idle_right_4.xpm"
// Move
# define MV_L0 "assets/player/move/left_0.xpm"
# define MV_L1 "assets/player/move/left_1.xpm"
# define MV_L2 "assets/player/move/left_2.xpm"
# define MV_L3 "assets/player/move/left_3.xpm"
# define MV_L4 "assets/player/move/left_4.xpm"
# define MV_L5 "assets/player/move/left_5.xpm"
# define MV_L6 "assets/player/move/left_6.xpm"
# define MV_L7 "assets/player/move/left_7.xpm"
# define MV_R0 "assets/player/move/right_0.xpm"
# define MV_R1 "assets/player/move/right_1.xpm"
# define MV_R2 "assets/player/move/right_2.xpm"
# define MV_R3 "assets/player/move/right_3.xpm"
# define MV_R4 "assets/player/move/right_4.xpm"
# define MV_R5 "assets/player/move/right_5.xpm"
# define MV_R6 "assets/player/move/right_6.xpm"
# define MV_R7 "assets/player/move/right_7.xpm"
// Collectibles
# define ACT_C0 "assets/player/action/collect_0.xpm"
# define ACT_C1 "assets/player/action/collect_1.xpm"
# define ACT_C20 "assets/player/action/collect_20.xpm"
# define ACT_C21 "assets/player/action/collect_21.xpm"
# define ACT_C22 "assets/player/action/collect_22.xpm"
# define ACT_C3 "assets/player/action/collect_3.xpm"
// Entry | Exit
# define P1_ENTRY "assets/player/io/entry.xpm"
# define P1_EXIT_0 "assets/player/io/exit_closed.xpm"
# define P1_EXIT_1 "assets/player/io/exit_open.xpm"

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
	int		x;
	int		y;
	int		dir;
	int		udlr;
	int		action;
	void	*img;
}	t_player;

typedef struct s_count
{
	int	p;
	int	e;
	int	c;
}	t_count;

typedef struct s_tiles
{
	void	*f[3];
	void	*s[8];
	void	*w[3];
	void	*io[3];
	void	*c[2];
}	t_tiles;

typedef struct s_sprites
{
	void	*idle[10];
	void	*move[16];
	void	*act[6];
	void	*io[3];
	void	*death[6];
}	t_sprites;

typedef struct s_image
{
	t_tiles		map;
	t_sprites	p1;
}	t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	t_point		**map;
	t_player	p1;
	int			end;
	t_image		img;
	t_count		cnt;
	int			mv_cnt;
}	t_game;

/*__Error description functions__*/
//Print error description in terminal
void	msg_error(int err_id, char *item);
//Free structure and exit program with message error
void	exit_error(int err_id, char *item, t_game *data);

void	free_map(t_point **map, int height);
void	destroy_tiles(t_game *data);
void	destroy_sprites(t_game *data);
void	free_game(t_game *data);

void	file_type_check(char *file);
int		wall_check(t_game *data);
int		type_count_check(t_game *data);
void	flood(t_point **map, t_point *pt);
int		path_check(t_game *data);
int		map_error(t_game *data);

void	print_map(t_game *data);

void	set_map_dim(t_game *data, char *file);
t_point	**init_map(t_game	*data);
void	set_point(t_point *pt, char type, int x, int y);
void	set_map(t_game *data, char *file);

/*__Map generation functions__*/
// Convert sea tile *.xpm to mlx_image
void	xpm_map_sea(t_game *data);
// Convert ground tile *.xpm to mlx_image
void	xpm_map_ground(t_game *data);
// Associate sea tile with corresponding image
void	sea_tile(t_game *data);
// Associate ground tile with corresponding image
void	gnd_tile(t_game *data);
// Link each tile of map [data->map[y][x].img] from image in ./assets
void	generate_map(t_game *data);

/*__Player sprites functions__*/
// Convert idle frames *.xpm to mlx_image
void	xpm_p1_idle(t_game *data);
// Convert move frames *.xpm to mlx_image
void	xpm_p1_move(t_game *data);
// Convert special frames *.xpm to mlx_image
void	xpm_p1_special(t_game *data);
// Add sprites to game data [data->img.p1] from image in ./assets/player
void	init_player(t_game *data);
t_game	*init_game(char *file);

t_point	*find_point(t_game *data, char c);
void	move_up(t_game *data);
void	move_down(t_game *data);
void	move_left(t_game *data);
void	move_right(t_game *data);

void	anim_move_p1(t_game *data, int fno);
void	anim_idle_p1(t_game *data, int fno);
void	anim_col_p1(t_game *data, int fno);

//Test
void	render_map(t_game *data);
int		exit_game(t_game *data);
void	play(t_game *data);

#endif