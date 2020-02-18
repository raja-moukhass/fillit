/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:45:26 by ramoukha          #+#    #+#             */
/*   Updated: 2019/07/24 16:21:29 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tet_check(char *buff)
{
	int		dot;
	int		hashtag;
	int		cnx;
	int		i;

	dot = 0;
	hashtag = 0;
	cnx = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '.')
			dot++;
		else if (buff[i] == '#')
		{
			hashtag++;
			cnx += (((i >= 5) && (buff[i - 5] == '#')) ? 1 : 0);
			cnx += (((i >= 1) && (buff[i - 1] == '#')) ? 1 : 0);
			cnx += (((i <= 13) && (buff[i + 5] == '#')) ? 1 : 0);
			cnx += (((i <= 17) && (buff[i + 1] == '#')) ? 1 : 0);
		}
		i++;
	}
	return (((cnx == 6 || cnx == 8) && (dot == 12) && (hashtag == 4) ? 1 : 0));
}

int		validation(int const fd, t_cordonnes **j_k, int *ptr)
{
	int		i;
	int		ret;
	char	buff[22];

	i = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (!(tet_check(buff)))
			return (0);
		j_k[i] = (t_cordonnes *)malloc(sizeof(t_cordonnes));
		extraction(buff, &j_k[i]);
		j_k[i]->h = get_max(j_k[i]->j);
		j_k[i]->w = get_max(j_k[i]->k);
		j_k[i]->alpha = 'A' + i;
		i++;
	}
	j_k[i] = 0;
	if ((buff[20] == '\0') && (i <= 26))
	{
		*ptr = i;
		return (1);
	}
	return (0);
}
