/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:01:58 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/23 12:59:04 by maaliber         ###   ########.fr       */
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
# define K_W 0x0077
# define K_A 0x0061
# define K_S 0x0073
# define K_D 0x0064
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
// Ground tiles
# define GND_0 "assets/map/floor/std_0.xpm"
# define GND_1 "assets/map/floor/std_1.xpm"
# define GND_2 "assets/map/floor/std_2.xpm"
// Obstacles tiles
# define WALL_0 "assets/map/wall/hole.xpm"
# define WALL_1 "assets/map/wall/mountain.xpm"
# define WALL_2 "assets/map/wall/stone.xpm"
// Entry | Exit tiles
# define ENTRY "assets/map/io/entry.xpm"
# define EXIT_0 "assets/map/io/exit_closed.xpm"
# define EXIT_1 "assets/map/io/exit_open.xpm"
// Collectible tiles
# define LOOT_0 "assets/map/collect/closed.xpm"
# define LOOT_1 "assets/map/collect/open.xpm"
// Enemies
# define SPK_0 "assets/map/enemies/spikes_0.xpm"
# define SPK_1 "assets/map/enemies/spikes_1.xpm"
# define SPK_2 "assets/map/enemies/spikes_2.xpm"
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

/*--      Number images      ---*/
# define X0 "assets/num/0.xpm"
# define X1 "assets/num/1.xpm"
# define X2 "assets/num/2.xpm"
# define X3 "assets/num/3.xpm"
# define X4 "assets/num/4.xpm"
# define X5 "assets/num/5.xpm"
# define X6 "assets/num/6.xpm"
# define X7 "assets/num/7.xpm"
# define X8 "assets/num/8.xpm"
# define X9 "assets/num/9.xpm"

/*--     End game images     ---*/
# define E0 "assets/black.xpm"
# define E1 "assets/win.xpm"
# define E2 "assets/game_over.xpm"

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
	E_MLX,
	E_IMG,
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
	int		c_cnt;
	void	*img;
}	t_player;

typedef struct s_count
{
	int	p;
	int	e;
	int	c;
}	t_count;

//Total image 76
typedef struct s_tiles
{
	void	*f[3];
	void	*s[8];
	void	*w[3];
	void	*io[3];
	void	*c[2];
	void	*e[3];
}	t_tiles;

typedef struct s_sprites
{
	void	*idle[10];
	void	*move[16];
	void	*act[6];
	void	*io[3];
}	t_sprites;

typedef struct s_image
{
	t_tiles		map;
	t_sprites	p1;
	void		*num[10];
	void		*end[3];
}	t_image;

# define IMG_NB 70

typedef struct s_game
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
	t_point		**map;
	t_player	p1;
	t_image		img;
	t_count		cnt;
	int			mv_cnt;
	int			end;
}	t_game;

/*__Utilised functions__*/

// Find unique point in map (data->map) of type "c".
t_point	*find_point(t_game *data, char c);
// Print map (data->map) terminal.
void	print_map(t_game *data);

/*__Program termination__*/

// Free map (data->map) terminal.
void	free_map(t_point **map, int height);
// Destroy MLX image if the image is initialised (non-NULL pointer).
void	destroy_image_v2(void *mlx_ptr, void *img);
// Destroy all MLX images used in game.
int		destroy_images(t_game *data);
/* Free all content of game : 
map, MLX pointer, MLX images, windows and display.*/
void	free_data(t_game *data);
// Free all content of game then exit program with status 0.
int		exit_game(t_game *data);

/*__Error management__*/

// Print error description in terminal.
void	msg_error(int err_id, char *item);
// Free all content of game then exit program with status 1.
void	exit_error(int err_id, char *item, t_game *data);
// Check for right file extension, only .ber allowed.
void	file_type_error(char *file);
// Check for right file extension, only .ber allowed.
int		img_error(t_game *data);

/*__Invalid map identification__*/

// Check if map is surrounded by walls.
int		wall_check(t_game *data);
// Check is player (P) nb = 1, exit (E) nb = 1, collectible (C) nb > 1.
int		type_count_check(t_game *data);
// Flood map to mark all accessible point from player data->map[y][x].acc.
void	flood(t_point **map, t_point *pt);
// Check if all collectibles and exit are accessible.
int		path_check(t_game *data);
// Check all map error if the map is invalid exit with status 1.
int		map_error(t_game *data);

/*__XPM conversion__*/

// Convert number *.xpm to mlx_image.
void	xpm_num(t_game *data);
// Convert end game *.xpm to mlx_image.
void	xpm_end_game(t_game *data);
// Convert sea tile *.xpm to mlx_image.
void	xpm_map_sea(t_game *data);
// Convert ground tile *.xpm to mlx_image.
void	xpm_map_ground(t_game *data);
// Convert idle frames *.xpm to mlx_image.
void	xpm_p1_idle(t_game *data);
// Convert move frames *.xpm to mlx_image.
void	xpm_p1_move(t_game *data);
// Convert special frames *.xpm to mlx_image.
void	xpm_p1_special(t_game *data);
// Convert all *.xpm files used in project to mlx_image.
void	xpm_images(t_game *data);

/*__Game initialisation__*/

/* Set map dimension based on infile 
if the map is not rectangular or GNL fails exit with status 1.*/
void	set_map_dim(t_game *data, char *file);
// Initialise map (t_point **) and each point (t_point) with coordinates.
t_point	**init_map(t_game	*data);
/* Fill map type data->map[y][x].type based on infile.
If GNL fails exit with status 1*/
void	set_map_type(t_game *data, char *file);
// Associate sea tile with corresponding image.
void	sea_tile(t_game *data);
// Associate ground tile with corresponding image.
void	gnd_tile(t_game *data);
// Link each tile of map (data->map[y][x].img) from image in ./assets.
void	generate_map(t_game *data);
// Initialise player (t_player) with starting coordinates and sprite.
void	init_player(t_game *data);
/* Initialise all content used in game :
All MLX images from xpm files, Map data and tiles, Player data.
If any error is encountered exit with status 1.*/
t_game	*init_game(char *file);

/*__Player mouvements__*/

/* Move the player (data->p1.x, data->p1.y) one square up if possible.
Start animation based on direction and target tile type.*/
void	move_up(t_game *data);
/* Move the player (data->p1.x, data->p1.y) one square down if possible.
Start animation based on direction and target tile type.*/
void	move_down(t_game *data);
/* Move the player (data->p1.x, data->p1.y) one square left if possible.
Start animation based on direction and target tile type.*/
void	move_left(t_game *data);
/* Move the player (data->p1.x, data->p1.y) one square right if possible.
Start animation based on direction and target tile type.*/
void	move_right(t_game *data);
// Display move count on the MLX window
void	print_mv_cnt(t_game *data, int mv_cnt);

/*__Display map and end-game screens__*/

// Render map background.
void	render_map(t_game *data);
// Display endgame screens lost or won game.
void	end_screen(t_game *data);

/*__Player animation__*/

/* Animate player after move input if target tile is type '0'.
Put user input on pending.*/
void	anim_move_p1(t_game *data);
// Animate idle player.
void	anim_idle_p1(t_game *data);
/* Animate player after move input if target tile is an active collectible
type 'C' (inactive type 'c'). Put user input on pending.*/
void	anim_col_p1(t_game *data);
// Animate player on special tiles.
void	anim_spe_p1(t_game *data);

/*__Core__*/

/* Update game status : based on nb of collectibles collected and player 
position. Check if game as ended.*/
void	update_game(t_game *data);
// MLX loop_hook handling animation based on player action (data->p1.action).
int		loop_hook(t_game *data);
// MLX key_hook handling user input.
int		key_hook(int key, t_game *data);
// Initialise MLX loop_hook, MLX key_hook, MLX loop, MLX key.
void	play(t_game *data);

/*__Main__*/
int		main(int ac, char **av);

#endif