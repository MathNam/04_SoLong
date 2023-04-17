/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:17:49 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:22:36 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct s_errdesc
{
	int		code;
	char	*msg;
} errdesc[] = {
	{E_SUCCESS, "No error"},
	{E_STD, 0},
	{E_NOMSG, 0},
	{E_ARG, "Error: invalid number of arguments"},
	{E_EXT, "Error: invalid file extension"},
	{E_FILE, "Error: no such file"},
	{E_MEM, "Error: memory allocation error"},
	{E_GNL, "Error: error executing get_next_line(...)"},
	{E_DIM, "Error: invalid map - not rectangular"},
	{E_EMPTY, "Error: invalid map - empty"},
	{E_WALL, "Error: invalid map - not closed/surrounded by walls"},
	{E_TYPE, "Error: invalid map - supported type are '01PECX'"},
	{E_CNT, "Error: invalid map - player/exit/collectible count invalid"},
	{E_PATH, "Error: invalid map - no valid path"},
	{E_MLX, "Error: MLX error"},
	{E_IMG, "Error: image error - something went wrong converting .xpm file"},
};

void	msg_error(int err_id, char *item)
{
	ft_printf("%s", errdesc[err_id].msg);
	if (item)
		ft_printf(": %s", item);
	write(1, "\n", 1);
}

void	exit_error(int err_id, char *item, t_game *data)
{
	if (err_id == E_STD)
		perror("");
	else if (err_id != E_NOMSG)
	{
		ft_printf("%s", errdesc[err_id].msg);
		if (item)
			ft_printf(": %s", item);
		write(1, "\n", 1);
	}
	free_data(data);
	exit(1);
}

void	file_type_error(char *file)
{
	int	fd;
	int	l;

	l = ft_strlen(file);
	if (l < 4)
		exit_error(E_EXT, 0, 0);
	if (ft_strncmp(file + (l - 4), ".ber", 5) != 0)
		exit_error(E_EXT, 0, 0);
	fd = open(file, O_RDWR);
	if (fd < 0)
		exit_error(E_FILE, 0, 0);
	close(fd);
}

int	img_error(t_game *data)
{
	void	**p;
	int		i;

	p = (void **)&data->img;
	i = 0;
	while (i < IMG_NB)
	{
		if (!p[i++])
			return (1);
	}
	return (0);
}
