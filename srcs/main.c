/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelamra <anelamra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:45:01 by ramoukha          #+#    #+#             */
/*   Updated: 2019/07/24 17:47:59 by anelamra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(void)
{
	ft_putendl("error");
	exit(-1);
}

int		ft_usage(void)
{
	ft_putendl("Usage: ./fillit [file_name]");
	return (0);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int			fd_ret[2];
	int			i;
	t_cordonnes	*j_k[27];
	char		**map;
	int			map_size;

	i = 0;
	if (argc != 2)
		return (ft_usage());
	fd_ret[0] = open(argv[1], O_RDONLY);
	if (fd_ret[0] < 0 || !(fd_ret[1] = validation(fd_ret[0], j_k, &i)))
		print_error();
	map_size = ft_sqrt(i * 4);
	map = new_map(map_size);
	while (!solver(map, map_size, j_k, 0))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map);
	exit(1);
}
