/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:20:21 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/27 16:03:22 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_point **map, int height)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < height && map[y])
		free(map[y++]);
	free(map);
}

void	free_game(t_game *data)
{
	if (!data)
		return ;
	free_map(data->map, data->height);
	free(data);
}
