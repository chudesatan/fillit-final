/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:49:27 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/09 16:49:29 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

char	is_valid(t_tetra_list *first_node, t_tetra_list *last_node)
{
	int				k;
	int				m;
	t_tetra_list	*fn;

	k = 0;
	while (k < 4)
	{
		m = 0;
		while (m < 4)
		{
			fn = first_node;
			while (fn != last_node)
			{
				if ((fn->x[k] + fn->this_x_0 == last_node->x[m] +
last_node->this_x_0) && (fn->y[k] + fn->this_y_0 ==
last_node->y[m] + last_node->this_y_0))
					return (0);
				fn = fn->next;
			}
			m++;
		}
		k++;
	}
	return (1);
}

int		findmax_tetra_size(t_tetra_list *f)
{
	int			k;
	int			x_max;
	static int	y_max;
	static char	d = 0;

	if (d == 1)
	{
		d = 0;
		return (y_max + 1);
	}
	x_max = 0;
	y_max = 0;
	k = 0;
	while (k <= 3)
	{
		if (f->x[k] > x_max)
			x_max = f->x[k];
		if (f->y[k] > y_max)
			y_max = f->y[k];
		k++;
	}
	d = 1;
	return (x_max + 1);
}

int		findmin_tetra_pos(t_tetra_list *f)
{
	int			k;
	int			x_min;
	static int	y_min;
	static char	d = 0;

	if (d == 1)
	{
		d = 0;
		return (y_min);
	}
	x_min = 3;
	y_min = 3;
	k = 0;
	while (k <= 3)
	{
		if (f->x[k] < x_min)
			x_min = f->x[k];
		if (f->y[k] < y_min)
			y_min = f->y[k];
		k++;
	}
	d = 1;
	return (x_min);
}

char	findmin_square_size(int n)
{
	int x;

	x = 4 * n;
	if (ft_sqrt(x) != 0)
		return (ft_sqrt(x));
	else
		while (ft_sqrt(x) == 0)
			x++;
	return (ft_sqrt(x));
}
