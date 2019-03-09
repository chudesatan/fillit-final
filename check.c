/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:48:19 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/09 16:48:21 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			else if (i >= 46341)
				return (0);
			i++;
		}
	}
	return (0);
}

int		help_norme4(int i, int j, t_tetra_list *tetra, int flag[2])
{
	if (i != j)
	if ((((tetra->x[i] == tetra->x[j] + 1) || (tetra->x[i] ==
	tetra->x[j] - 1)) && (tetra->y[i] == tetra->y[j])) ||
	(((tetra->y[i] == tetra->y[j] + 1) || (tetra->y[i] ==
	tetra->y[j] - 1)) && (tetra->x[i] == tetra->x[j])))
	flag[1]++;
	if (flag[1] == 3)
	return (1);
	if (flag[1] == 2)
	{
		if (flag[0] == 1)
		return (1);
		else
		flag[0] = 1;
	}
	return (0);
}

int		check_tetra(t_tetra_list *tetra)
{
	int	i;
	int	j;
	int	flag[2];

	flag[0] = 0;
	flag[1] = 0;
	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (help_norme4(i, j, tetra, flag) == 1)
			return (1);
			j++;
		}
		flag[1] = 0;
		i++;
	}
	return (0);
}

void	input_tetra(int type_x[4], int type_y[4], t_tetra_list **node)
{
	int x_min;
	int y_min;

	add_tetra_type_x(type_x[0], type_x[1], type_x[2], type_x[3]);
	add_tetra_type_y(type_y[0], type_y[1], type_y[2], type_y[3]);
	x_min = findmin_tetra_pos(*node);
	y_min = findmin_tetra_pos(*node);
	add_tetra_type_x(type_x[0] - x_min, type_x[1] - x_min, type_x[2] - x_min, type_x[3] - x_min);
	add_tetra_type_y(type_y[0] - y_min, type_y[1] - y_min, type_y[2] - y_min, type_y[3] - y_min);
	init_this_tetra_pos(node);
}
