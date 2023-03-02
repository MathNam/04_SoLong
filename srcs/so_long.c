/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:46:16 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/02 12:07:04 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_type_check(char *file)
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

int	main(int ac, char **av)
{
	t_game	*data;

	if (ac != 2)
		exit_error(E_ARG, 0, 0);
	file_type_check(av[1]);
	data = init_game(av[1]);
	generate_map(data);
	play(data);
	return (0);
}
