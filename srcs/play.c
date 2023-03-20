/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:09:06 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/20 17:27:00 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *data)
{
	t_point		*ex;

	if (data->p1.action > 0)
		return (0);
	if (key == K_ESC)
		exit_game(data);
	if (data->end)
		return (0);
	if (key == K_W)
		move_up(data);
	if (key == K_A)
		move_left(data);
	if (key == K_S)
		move_down(data);
	if (key == K_D)
		move_right(data);
	if (data->p1.c_cnt == data->cnt.c)
	{
		ex = find_point(data, 'E');
		data->map[ex->y][ex->x].img = data->img.map.io[2];
		data->cnt.c = -1;
	}
	if (data->cnt.c == -1 && data->map[data->p1.y][data->p1.x].type == 'E')
		data->end = 1;
	return (0);
}

int	loop_hook(t_game *data)
{
	static int	i;

	if (data->end > 0 && !(i % 100))
		end_screen(data);
	if (++i != 1500)
		return (0);
	if (data->end == 0)
	{
		render_map(data);
		if (data->p1.action == 0)
			anim_idle_p1(data);
		else if (data->p1.action == 1)
			anim_move_p1(data);
		else if (data->p1.action == 2)
			anim_col_p1(data);
		else if (data->p1.action == -1)
			anim_spe_p1(data);
		print_mv_cnt(data, data->mv_cnt);
	}
	i = 0;
	return (0);
}

void	play(t_game *data)
{
	mlx_hook(data->win, 17, 0, exit_game, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop_hook(data->ptr, loop_hook, data);
	mlx_loop(data->ptr);
}
