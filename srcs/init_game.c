/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:31 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/27 16:57:01 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_dim(t_game *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(E_FILE, file, data);
	line = get_next_line(fd);
	data->width = ft_linelen(line);
	data->height = 0;
	while (line)
	{
		if ((size_t)data->width != ft_linelen(line))
		{
			free(line);
			exit_error(E_DIM, 0, data);
		}
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (data->width == 0)
		exit_error(E_EMPTY, 0, data);
}

t_point	**init_map(t_game	*data)
{
	t_point	**map;
	int		y;

	map = malloc(sizeof(t_point *) * data->height);
	if (!map)
		exit_error(E_MEM, 0, data);
	y = 0;
	while (y < data->height)
	{
		map[y] = malloc(sizeof(t_point) * data->width);
		if (!map[y])
		{
			free_map(map, data->height);
			exit_error(E_MEM, 0, data);
		}
		y++;
	}
	return (map);
}

void	set_point(t_point *pt, char type, int x, int y)
{
	pt->type = type;
	pt->acc = 0;
	pt->x = x;
	pt->y = y;
}

void	set_map(t_game *data, char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	data->map = init_map(data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(E_FILE, file, data);
	y = 0;
	while (y < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			exit_error(E_GNL, 0, data);
		x = 0;
		while (x < data->width)
		{
			set_point(&data->map[y][x], line[x], x, y);
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
}

t_game	*init_game(char *file)
{
	t_game	*data;
	t_point	*p1_pt;

	data = ft_calloc(1, sizeof(t_game));
	if (!data)
		exit_error(E_MEM, 0, 0);
	set_map_dim(data, file);
	set_map(data, file);
	if (map_error(data))
		exit_error(map_error(data), 0, data);
	p1_pt = find_player(data);
	data->p1.x = p1_pt->x;
	data->p1.y = p1_pt->y;
	data->p1.dir = 0;
	p1_pt->type = '0';
	return (data);
}
