/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:09:06 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/13 17:19:30 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *data)
{
	if (data->p1.action > 0)
		return (0);
	if (key == K_ESC)
		exit_game(data);
	if (key == K_W)
		move_up(data);
	if (key == K_A)
		move_left(data);
	if (key == K_S)
		move_down(data);
	if (key == K_D)
		move_right(data);
	if (data->end > 0)
	{
		ft_printf("---------------\nEND\n---------------\n");
		exit_game(data);
	}
	return (0);
}

int	loop_hook(t_game *data)
{
	static int	i;
	static int	idle_fno;
	static int	act_fno;

	i++;
	if (i == 2500)
	{
		/*if (data->end == 1)
			return(win_screen(data), 0);
		if (data->end == 2)
			return(death_screen(data), 0);*/
		render_map(data);
		if (data->p1.action == 0)
			anim_idle_p1(data, idle_fno++);
		else if (data->p1.action == 1)
			anim_move_p1(data, act_fno++);
		else if (data->p1.action == 2)
			anim_col_p1(data, act_fno++);
		if (data->p1.action == -1)
		{
			act_fno = 0;
			idle_fno = 0;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->p1.img,
				data->p1.x * IMG_W, data->p1.y * IMG_H);
		}
		act_fno = act_fno % 8;
		idle_fno = idle_fno % 5;
		i = 0;
	}
	return (0);
}

int	exit_game(t_game *data)
{
	destroy_sprites(data);
	destroy_tiles(data);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_game(data);
	exit(0);
	return (0);
}

void	play(t_game *data)
{
	mlx_hook(data->mlx_win, 17, 0, exit_game, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_loop(data->mlx_ptr);
}
