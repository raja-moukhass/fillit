/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:20:46 by ramoukha          #+#    #+#             */
/*   Updated: 2019/07/24 16:48:19 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solver(char **map, int map_size, t_cordonnes **tet, int i)
{
	int		x;
	int		y;

	y = -1;
	if (tet[i] == 0)
		return (1);
	while (++y < map_size - tet[i]->h)
	{
		x = -1;
		while (++x < map_size - tet[i]->w)
		{
			if (check_place(map, tet[i], y, x))
			{
				place(map, tet[i], y, x);
				if (solver(map, map_size, tet, i + 1))
					return (1);
				delete_tet(map, map_size, tet[i]->alpha);
			}
		}
	}
	return (0);
}
