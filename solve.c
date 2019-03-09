/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:48:59 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/09 16:49:02 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

int		solve_last_node(t_tetra_list **first_node, t_tetra_list **last_node, int square_size)
{
	int tetra_pos_x;
	int tetra_pos_y;

	tetra_pos_y = 0;
	while (tetra_pos_y + (*last_node)->this_max_y <= square_size + 1)
	{
		tetra_pos_x = 0;
		while (tetra_pos_x + (*last_node)->this_max_x <= square_size + 1)
		{
			set_tetra_pos(tetra_pos_x, tetra_pos_y, last_node);
			if (is_valid(*first_node, *last_node))
				if (((*last_node)->this_max_x + (*last_node)->this_x_0) <= square_size && ((*last_node)->this_max_y + (*last_node)->this_y_0) <= square_size)
					print_composition(first_node, square_size - 1, 0);
			tetra_pos_x++;
		}
		tetra_pos_y++;
	}
	return (0);
}

int		solve_middle_node(t_tetra_list **first_node,
t_tetra_list **middle_node, t_tetra_list **last_node, int square_size)
{
	t_tetra_list *temp;

	if (*middle_node == *last_node)
	{
		solve_last_node(first_node, last_node, square_size);
		return (0);
	}
	(*middle_node)->this_y_0 = 0;
	while (((*middle_node)->this_max_y + (*middle_node)->this_y_0) <= square_size)
	{
		if (is_valid(*first_node, *middle_node) &&
((*middle_node)->this_max_x + (*middle_node)->this_x_0) <= square_size)
		{
			temp = (*middle_node)->next;
			solve_middle_node(first_node, &temp, last_node, square_size);
		}
		if (((*middle_node)->this_max_x + (*middle_node)->this_x_0) > square_size)
		{
			(*middle_node)->this_x_0 = 0;
			inc_tetra_pos_y(middle_node);
		}
		else
			inc_tetra_pos_x(middle_node);
	}
	return (0);
}

void	solve_first_node(t_tetra_list **first_node, t_tetra_list **last_node, int square_size)
{
	t_tetra_list *temp;

	(*first_node)->this_y_0 = 0;
	while (((*first_node)->this_max_y + (*first_node)->this_y_0) <= square_size)
	{
		if (((*first_node)->this_max_x + (*first_node)->this_x_0) <= square_size)
		{
			temp = (*first_node)->next;
			solve_middle_node(first_node, &temp, last_node, square_size);
		}
		if (((*first_node)->this_max_x + (*first_node)->this_x_0) > square_size)
		{
			(*first_node)->this_x_0 = 0;
			inc_tetra_pos_y(first_node);
		}
		else
			inc_tetra_pos_x(first_node);
	}
}

void	solve(t_tetra_list **first_node, t_tetra_list **last_node, int num)
{
	int	square_size;

	square_size = 0;
	square_size = findmin_square_size(num + 1);
	if ((*first_node)->next == NULL)
	{
		print_composition(first_node, MAX(((*first_node)->this_max_x - 1), ((*first_node)->this_max_y - 1)), 0);
		final_message(first_node, 0);
	}
	while (square_size++)
	solve_first_node(first_node, last_node, square_size - 1);
	final_message(first_node, 0);
}
