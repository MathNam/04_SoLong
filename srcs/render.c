/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:37 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/02 12:14:16 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *data)
{	
	data->spt.f[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/floor.xpm", 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->spt.f[0], 0, 0);
}