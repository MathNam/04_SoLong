/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:28:27 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/16 15:47:01 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	*find_point(t_game *data, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x].type == c)
				return (&data->map[y][x]);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	move_up(t_game *data)
{
	t_player	*p1;

	p1 = &data->p1;
	p1->udlr = 3;
	if (data->map[p1->y - 1][p1->x].type != '1')
	{
		p1->action = 1;
		if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = 0;
		p1->y = p1->y - 1;
		data->mv_cnt++;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = 'c';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			p1->c_cnt++;
			p1->action = 2;
		}
		else if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = -1;
	}
}

void	move_down(t_game *data)
{
	t_player	*p1;

	p1 = &data->p1;
	p1->udlr = 2;
	if (data->map[p1->y + 1][p1->x].type != '1')
	{
		p1->action = 1;
		if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = 0;
		p1->y = p1->y + 1;
		data->mv_cnt++;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = 'c';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			p1->c_cnt++;
			p1->action = 2;
		}
		else if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = -1;
	}
}

void	move_left(t_game *data)
{
	t_player	*p1;

	p1 = &data->p1;
	p1->dir = 1;
	p1->udlr = 1;
	if (data->map[p1->y][p1->x - 1].type != '1')
	{
		p1->action = 1;
		if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = 0;
		p1->x = p1->x - 1;
		data->mv_cnt++;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = 'c';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			p1->c_cnt++;
			p1->action = 2;
		}
		else if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = -1;
	}
}

void	move_right(t_game *data)
{
	t_player	*p1;

	p1 = &data->p1;
	p1->dir = 0;
	p1->udlr = 0;
	if (data->map[p1->y][p1->x + 1].type != '1')
	{
		p1->action = 1;
		if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = 0;
		p1->x = p1->x + 1;
		data->mv_cnt++;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = 'c';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			p1->c_cnt++;
			p1->action = 2;
		}
		else if (ft_strchr("cEI", data->map[p1->y][p1->x].type))
			p1->action = -1;
	}
}
