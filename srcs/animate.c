/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:39:22 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/17 18:43:49 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_move_p1(t_game *data)
{
	t_player	*p1;
	static int	fno;

	p1 = &data->p1;
	if (p1->dir == 0)
		data->p1.img = data->img.p1.move[8 + fno];
	if (p1->dir == 1)
		data->p1.img = data->img.p1.move[fno];
	if (fno == 7)
		data->p1.action = 0;
	if (p1->udlr == 0)
		mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
			(p1->x - 1) * IMG_W + 20 + fno * 8, p1->y * IMG_H + 8);
	if (p1->udlr == 1)
		mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
			(p1->x + 1) * IMG_W + 4 - fno * 8, p1->y * IMG_H + 8);
	if (p1->udlr == 2)
		mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
			p1->x * IMG_W + 12, (p1->y - 1) * IMG_H + 16 + fno * 8);
	if (p1->udlr == 3)
		mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
			p1->x * IMG_W + 12, (p1->y + 1) * IMG_H - fno * 8);
	fno++;
	fno %= 8;
}

void	anim_idle_p1(t_game *data)
{
	t_player	*p1;
	static int	fno;

	p1 = &data->p1;
	if (p1->dir == 0)
		data->p1.img = data->img.p1.idle[5 + fno];
	if (p1->dir == 1)
		data->p1.img = data->img.p1.idle[fno];
	mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
		p1->x * IMG_W + 12, p1->y * IMG_H + 8);
	fno++;
	fno %= 5;
}

void	anim_col_p1(t_game *data)
{
	t_player	*p1;
	static int	fno;

	p1 = &data->p1;
	if (fno < 8)
		data->p1.img = data->img.p1.act[0];
	else if (fno < 16)
		data->p1.img = data->img.p1.act[1];
	else if (fno < 62)
	{
		if (data->p1.c_cnt == 1)
			data->p1.img = data->img.p1.act[2];
		if (data->p1.c_cnt == 2)
			data->p1.img = data->img.p1.act[3];
		if (data->p1.c_cnt > 2)
			data->p1.img = data->img.p1.act[4];
	}
	else
		data->p1.img = data->img.p1.act[5];
	mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
		p1->x * IMG_W, p1->y * IMG_H);
	if (fno == 63)
		data->p1.action = -1;
	fno++;
	fno %= 64;
}

void	anim_spe_p1(t_game *data)
{
	t_player	*p1;

	p1 = &data->p1;
	if (data->map[p1->y][p1->x].type == 'c')
		data->p1.img = data->img.p1.act[5];
	if (data->map[p1->y][p1->x].type == 'I')
		data->p1.img = data->img.p1.io[0];
	if (data->map[p1->y][p1->x].type == 'E')
	{
		if (p1->c_cnt == data->cnt.c)
			data->p1.img = data->img.p1.io[2];
		else
			data->p1.img = data->img.p1.io[1];
	}
	mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
		p1->x * IMG_W, p1->y * IMG_H);
}

void	anim_death_p1(t_game *data)
{
	t_player	*p1;

	p1 = &data->p1;
	if (data->map[p1->y][p1->x].type == 'c')
		data->p1.img = data->img.p1.act[5];
	if (data->map[p1->y][p1->x].type == 'I')
		data->p1.img = data->img.p1.io[0];
	if (data->map[p1->y][p1->x].type == 'E')
	{
		if (p1->c_cnt == data->cnt.c)
			data->p1.img = data->img.p1.io[1];
		else
			data->p1.img = data->img.p1.io[2];
	}
	mlx_put_image_to_window(data->ptr, data->win, data->p1.img,
		p1->x * IMG_W, p1->y * IMG_H);
}
