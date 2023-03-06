/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:09:06 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/06 18:44:15 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *data)
{
	printf(("Key nb: %d\n"), key);
	render_map(data);
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
	print_map(data);
	if (data->end > 0)
	{
		ft_printf("---------------\nEND\n---------------\n");
		exit_game(data);
	}
	render_map(data);
	return (0);
}

int	exit_game(t_game *data)
{
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
	xpm_player(data);
	mlx_hook(data->mlx_win, 17, 0, exit_game, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	//mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_loop(data->mlx_ptr);
}
