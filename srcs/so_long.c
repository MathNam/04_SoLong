/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:46:16 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/20 16:58:40 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*data;

	if (ac != 2)
		exit_error(E_ARG, 0, 0);
	file_type_error(av[1]);
	data = init_game(av[1]);
	play(data);
	return (0);
}
