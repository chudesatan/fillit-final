/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:48:41 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/09 16:48:43 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

char	help_norme5(char *flag, t_tetra_list **f, int i, int j)
{
	int				k;
	char			l;
	t_tetra_list	*fn;

	k = 0;
	*flag = 0;
	while (k < 4)
	{
		l = 'A';
		fn = *f;
		while (fn != NULL)
		{
			if ((fn->x[k] + fn->this_x_0 == j) &&
	(fn->y[k] + fn->this_y_0 == i))
			{
				ft_putchar(l);
				*flag = 1;
				return (l);
			}
			l++;
			fn = fn->next;
		}
		k++;
	}
	return (0);
}

void	print_composition(t_tetra_list **f, int square_size, char c_copy)
{
	int		i;
	int		j;
	char	c;
	char	flag;

	flag = 0;
	i = 0;
	while (i <= square_size)
	{
		j = 0;
		while (j <= square_size)
		{
			if ((c_copy = help_norme5(&flag, f, i, j)) != 0)
				c = c_copy;
			if (flag != 1 && (c = '.') == '.')
				ft_putchar(c);
			j++;
		}
		c = '\n';
		ft_putchar(c);
		i++;
	}
	final_message(f, 0);
}

void	help_norme3(int type_x[5], int type_y[5],
t_tetra_list *node[26], int num[2])
{
	if (type_y[4] == 5)
	{
		if (num[0] == 4)
		{
			input_tetra(type_x, type_y, &node[num[1]]);
			if (!check_tetra(node[num[1]]))
				final_message(&node[0], 1);
			num[1]++;
			if (num[1] == 26)
				final_message(&node[0], 1);
			node[num[1]] = add_tetra(&node[num[1] - 1]);
			num[0] = 0;
		}
		else
			final_message(&node[0], 1);
		type_y[4] = 0;
		type_x[4] = 4;
	}
	else
		final_message(&node[0], 1);
}

void	help_norme2(int type_x[5], int type_y[5],
t_tetra_list *node[26], int num[2])
{
	char	*temp;

	temp = g_line;
	if (type_x[4] != 4)
		final_message(&node[0], 1);
	type_x[4] = 0;
	while (*temp != '\0')
	{
		if (*temp != '.' && *temp != '#')
			final_message(&node[0], 1);
		else if (*temp == '#')
		{
			type_x[num[0]] = type_x[4];
			type_y[num[0]] = type_y[4];
			num[0]++;
		}
		temp++;
		type_x[4]++;
	}
}

int		read_input(int fd, t_tetra_list *node[26])
{
	int		type_x[5];
	int		type_y[5];
	int		num[2];

	num[1] = 0;
	num[0] = 0;
	type_x[4] = 4;
	type_y[4] = 0;
	while (get_next_line((const int)fd, &g_line) > 0)
	{
		help_norme2(type_x, type_y, node, num);
		type_y[4]++;
		if (*g_line == '\0')
			help_norme3(type_x, type_y, node, num);
		free(g_line);
	}
	if (type_y[4] != 4)
		final_message(&node[0], 1);
	input_tetra(type_x, type_y, &node[num[1]]);
	if (!check_tetra(node[num[1]]) || num[0] != 4)
		final_message(&node[0], 1);
	return (num[1]);
}
