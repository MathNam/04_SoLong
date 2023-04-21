/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:29:09 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/21 13:20:27 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->width)
	{
		if (data->map[0][x].type != '1' ||
			data->map[data->height - 1][x].type != '1')
			return (E_WALL);
		x++;
	}
	y = 0;
	while (y < data->height)
	{
		if (data->map[y][0].type != '1' ||
			data->map[y][data->width - 1].type != '1')
			return (E_WALL);
		y++;
	}
	return (0);
}

int	type_count_check(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (!ft_ischarset(data->map[y][x].type, "01PECX"))
				return (E_TYPE);
			if (data->map[y][x].type == 'P')
				data->cnt.p++;
			if (data->map[y][x].type == 'E')
				data->cnt.e++;
			if (data->map[y][x].type == 'C')
				data->cnt.c++;
			x++;
		}
		y++;
	}
	if (data->cnt.p != 1 || data->cnt.e != 1 || data->cnt.c < 1)
		return (E_CNT);
	return (0);
}

void	flood(t_point **map, t_point *pt)
{
	pt->acc = 1;
	if (map[pt->y][pt->x + 1].type != '1' && map[pt->y][pt->x + 1].type != 'X'
		&& map[pt->y][pt->x + 1].acc == 0)
		flood(map, &map[pt->y][pt->x + 1]);
	if (map[pt->y + 1][pt->x].type != '1' && map[pt->y + 1][pt->x].type != 'X'
		&& map[pt->y + 1][pt->x].acc == 0)
		flood(map, &map[pt->y + 1][pt->x]);
	if (map[pt->y][pt->x - 1].type != '1' && map[pt->y][pt->x - 1].type != 'X'
		&& map[pt->y][pt->x - 1].acc == 0)
		flood(map, &map[pt->y][pt->x - 1]);
	if (map[pt->y - 1][pt->x].type != '1' && map[pt->y - 1][pt->x].type != 'X'
		&& map[pt->y - 1][pt->x].acc == 0)
		flood(map, &map[pt->y - 1][pt->x]);
}

int	path_check(t_game *data)
{
	t_point	*start;
	int		x;
	int		y;

	start = find_point(data, 'P');
	flood(data->map, start);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (ft_ischarset(data->map[y][x].type, "EC"))
			{
				if (data->map[y][x].acc != 1)
					return (E_PATH);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	map_error(t_game *data)
{
	static int	err_id;

	if (!err_id)
		err_id = wall_check(data);
	if (!err_id)
		err_id = type_count_check(data);
	if (!err_id)
		err_id = path_check(data);
	return (err_id);
}
