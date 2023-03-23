/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:31 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/23 12:58:57 by maaliber         ###   ########.fr       */
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
	int		x;
	int		y;

	map = malloc(sizeof(t_point *) * data->height);
	if (!map)
		exit_error(E_MEM, 0, data);
	y = 0;
	while (y < data->height)
	{
		map[y] = ft_calloc(1, sizeof(t_point) * data->width);
		if (!map[y])
		{
			free_map(map, data->height);
			exit_error(E_MEM, 0, data);
		}
		x = 0;
		while (x < data->width)
		{
			map[y][x].x = x;
			map[y][x++].y = y;
		}
		y++;
	}
	return (map);
}

void	set_map_type(t_game *data, char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

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
			data->map[y][x].type = line[x];
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
}

void	init_player(t_game *data)
{
	t_point	*p1_pt;

	p1_pt = find_point(data, 'P');
	data->p1.x = p1_pt->x;
	data->p1.y = p1_pt->y;
	data->p1.action = -1;
	p1_pt->type = 'I';
	data->p1.img = data->img.p1.io[0];
}

t_game	*init_game(char *file)
{
	t_game	*data;

	data = ft_calloc(1, sizeof(t_game));
	if (!data)
		exit_error(E_MEM, 0, 0);
	set_map_dim(data, file);
	data->map = init_map(data);
	set_map(data, file);
	if (map_error(data))
		exit_error(map_error(data), 0, data);
	data->ptr = mlx_init();
	if (!data->ptr)
		exit_error(E_MLX, 0, data);
	data->win = mlx_new_window(data->ptr,
			IMG_W * data->width, IMG_W * data->height, "so_long");
	if (!data->win)
		exit_error(E_MLX, 0, data);
	xpm_images(data);
	if (img_error(data))
		exit_error(E_IMG, 0, data);
	generate_map(data);
	init_player(data);
	return (data);
}
