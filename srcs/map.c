/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:59:22 by ramoukha          #+#    #+#             */
/*   Updated: 2019/07/24 15:50:09 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_map(int size)
{
	char	**map;
	int		i;

	i = -1;
	map = (char **)ft_memalloc(sizeof(char *) * size + 1);
	while (++i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', size);
	}
	map[i] = NULL;
	return (map);
}

void	print_map(char **map)
{
	while (*map)
		ft_putendl(*map++);
}

int		check_place(char **map, t_cordonnes *list, int y, int x)
{
	int i;

	i = -1;
	while (++i < 4)
		if (map[list->j[i] + y][list->k[i] + x] != '.')
			return (0);
	return (1);
}

int		place(char **map, t_cordonnes *list, int y, int x)
{
	int i;

	i = -1;
	while (++i < 4)
		if (map[list->j[i] + y][list->k[i] + x] == '.')
			map[list->j[i] + y][list->k[i] + x] = list->alpha;
	return (1);
}

void	delete_tet(char **map, int map_size, char letter)
{
	int i;
	int j;

	i = -1;
	while (++i < map_size)
	{
		j = -1;
		while (++j < map_size)
			if (map[i][j] == letter)
				map[i][j] = '.';
	}
}
