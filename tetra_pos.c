/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:49:14 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/09 16:49:16 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

void	tetra_lstdel(t_tetra_list **alst)
{
	t_tetra_list *tmp;

	while (*alst)
	{
		tmp = *alst;
		free(tmp);
		*alst = NULL;
		*alst = tmp->next;
	}
}

void	set_tetra_pos(int pos_x, int pos_y, t_tetra_list **node)
{
	(*node)->this_x_0 = pos_x;
	(*node)->this_y_0 = pos_y;
}

void	inc_tetra_pos_x(t_tetra_list **node)
{
	((*node)->this_x_0)++;
}

void	inc_tetra_pos_y(t_tetra_list **node)
{
	((*node)->this_y_0)++;
}

void	final_message(t_tetra_list **f, char exit_flag)
{
	if (f != NULL)
		tetra_lstdel(f);
	if (exit_flag == 1)
		ft_putstr("error\n");
	exit(exit_flag);
}
