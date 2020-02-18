/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anelamra <anelamra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:46:42 by ramoukha          #+#    #+#             */
/*   Updated: 2019/07/24 17:49:28 by anelamra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_cordonnes
{
	int		j[4];
	int		k[4];
	int		h;
	int		w;
	char	alpha;
}				t_cordonnes;

int				validation(int const fd, t_cordonnes **j_k, int *ptr);
void			extraction(char	*buff, t_cordonnes **j_k);
void			shifting(t_cordonnes **j_k);

char			**new_map(int size);
void			print_map(char **map);
int				check_place(char **map, t_cordonnes *list, int y, int x);
int				place(char **map, t_cordonnes *list, int y, int x);
void			delete_tet(char **map, int map_size, char letter);
int				solver(char **map, int map_size, t_cordonnes **tet, int i);
int				get_max(int *tab);
void			free_map(char **map, int map_size);

#endif
