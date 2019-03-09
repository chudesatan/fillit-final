/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:48:00 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/09 16:48:02 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

t_tetra_list	*add_tetra(t_tetra_list **prev)
{
	t_tetra_list *temp;

	temp = (t_tetra_list *)malloc(sizeof(t_tetra_list));
	temp->next = NULL;
	temp->prev = *prev;
	(*prev)->next = temp;
	g_temp = temp;
	return (temp);
}

t_tetra_list	*add_tetra_0(void)
{
	t_tetra_list *temp;

	temp = (t_tetra_list *)malloc(sizeof(t_tetra_list));
	temp->next = NULL;
	temp->prev = NULL;
	g_temp = temp;
	return (temp);
}

void			add_tetra_type_x(signed int x0, signed int x1,
signed int x2, signed int x3)
{
	g_temp->x[0] = x0;
	g_temp->x[1] = x1;
	g_temp->x[2] = x2;
	g_temp->x[3] = x3;
}

void			add_tetra_type_y(signed int y0, signed int y1,
signed int y2, signed int y3)
{
	g_temp->y[0] = y0;
	g_temp->y[1] = y1;
	g_temp->y[2] = y2;
	g_temp->y[3] = y3;
}

void			init_this_tetra_pos(t_tetra_list **temp)
{
	(*temp)->this_max_x = findmax_tetra_size(*temp);
	(*temp)->this_max_y = findmax_tetra_size(*temp);
	(*temp)->this_x_0 = 0;
	(*temp)->this_y_0 = 0;
}
