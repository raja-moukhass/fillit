/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelamra <anelamra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:43:34 by ramoukha          #+#    #+#             */
/*   Updated: 2019/07/24 17:49:00 by anelamra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(char **map, int map_size)
{
	int i;

	i = -1;
	while (++i < map_size)
		free(map[i]);
	free(map);
}

int		get_max(int *tab)
{
	int max;
	int i;

	i = -1;
	max = tab[0];
	while (++i < 4)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return (max);
}

void	extraction(char *buff, t_cordonnes **j_k)
{
	int i;
	int hash;
	int p;

	p = -1;
	i = 0;
	hash = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			(*j_k)->j[hash] = (i / 5);
			(*j_k)->k[hash] = (i % 5);
			hash++;
		}
		i++;
	}
	shifting(j_k);
}

void	shifting(t_cordonnes **j_k)
{
	int	i;
	int p;

	p = -1;
	while ((*j_k)->j[0] != 0 &&\
			(*j_k)->j[1] != 0 && (*j_k)->j[2] != 0 && (*j_k)->j[3] != 0)
	{
		i = 0;
		while (i < 4)
		{
			(*j_k)->j[i] -= 1;
			i++;
		}
	}
	while ((*j_k)->k[0] != 0 &&\
			(*j_k)->k[1] != 0 && (*j_k)->k[2] != 0 && (*j_k)->k[3] != 0)
	{
		i = 0;
		while (i < 4)
		{
			(*j_k)->k[i] -= 1;
			i++;
		}
	}
}
