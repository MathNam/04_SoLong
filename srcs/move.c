/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:28:27 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/13 17:11:11 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//struct s_direction
//{
//	int[4][2] 
//} errdesc[] = {
//	{E_SUCCESS, "No error"},
//	{E_STD, 0},
//	{E_NOMSG, 0},
//	{E_ARG, "invalid number of arguments"},
//	{E_EXT, "invalid file extension"},
//	{E_FILE, "no such file"},
//	{E_MEM, "memory allocation error"},
//	{E_GNL, "error executing get_next_line(...)"},
//	{E_DIM, "invalid map - not rectangular"},
//	{E_EMPTY, "invalid map - empty"},
//	{E_WALL, "invalid map - not closed/surrounded by walls"},
//	{E_TYPE, "invalid map - supported type are '01PEC'"},
//	{E_CNT, "invalid map - player/exit/collectible count invalid"},
//	{E_PATH, "invalid map - no valid path"},
//};

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
	t_point		*ex;

	p1 = &data->p1;
	p1->udlr = 3;
	if (data->map[p1->y - 1][p1->x].type != '1')
	{
		p1->action = 1;
		p1->y = p1->y - 1;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = '0';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			data->cnt.c--;
			p1->action = 2;
			if (data->cnt.c == 0)
			{
				ex = find_point(data, 'E');
				data->map[ex->y][ex->x].img = data->img.map.io[2];
			}
		}
		if (data->map[p1->y][p1->x].type == 'F')
			data->end = 2;
		if (data->map[p1->y][p1->x].type == 'E' && data->cnt.c == 0)
			data->end = 1;
	}
}

void	move_down(t_game *data)
{
	t_player	*p1;
	t_point		*ex;

	p1 = &data->p1;
	p1->udlr = 2;
	if (data->map[p1->y + 1][p1->x].type != '1')
	{
		p1->action = 1;
		p1->y = p1->y + 1;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = '0';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			data->cnt.c--;
			p1->action = 2;
			if (data->cnt.c == 0)
			{
				ex = find_point(data, 'E');
				data->map[ex->y][ex->x].img = data->img.map.io[2];
			}
		}
		if (data->map[p1->y][p1->x].type == 'F')
			data->end = 2;
		if (data->map[p1->y][p1->x].type == 'E' && data->cnt.c == 0)
			data->end = 1;
	}
}

void	move_left(t_game *data)
{
	t_player	*p1;
	t_point		*ex;

	p1 = &data->p1;
	p1->dir = 1;
	p1->udlr = 1;
	if (data->map[p1->y][p1->x - 1].type != '1')
	{
		p1->action = 1;
		p1->x = p1->x - 1;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = '0';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			data->cnt.c--;
			p1->action = 2;
			if (data->cnt.c == 0)
			{
				ex = find_point(data, 'E');
				data->map[ex->y][ex->x].img = data->img.map.io[2];
			}
		}
		if (data->map[p1->y][p1->x].type == 'F')
			data->end = 2;
		if (data->map[p1->y][p1->x].type == 'E' && data->cnt.c == 0)
			data->end = 1;
	}
}

void	move_right(t_game *data)
{
	t_player	*p1;
	t_point		*ex;
	
	p1 = &data->p1;
	p1->dir = 0;
	p1->udlr = 0;
	if (data->map[p1->y][p1->x + 1].type != '1')
	{
		p1->action = 1;
		p1->x = p1->x + 1;
		if (data->map[p1->y][p1->x].type == 'C')
		{
			data->map[p1->y][p1->x].type = '0';
			data->map[p1->y][p1->x].img = data->img.map.c[1];
			data->cnt.c--;
			p1->action = 2;
			if (data->cnt.c == 0)
			{
				ex = find_point(data, 'E');
				data->map[ex->y][ex->x].img = data->img.map.io[2];
			}
		}
		if (data->map[p1->y][p1->x].type == 'F')
			data->end = 2;
		if (data->map[p1->y][p1->x].type == 'E' && data->cnt.c == 0)
			data->end = 1;
	}
}
