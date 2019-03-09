/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:46:42 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/07 21:32:11 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX(a, b) ((a >= b) ? (a) : (b))

typedef	struct	s_tetra_list
{
	signed int			x[4];
	signed int			y[4];
	signed int			this_x_0;
	signed int			this_y_0;
	signed int			this_max_x;
	signed int			this_max_y;
	struct s_tetra_list	*next;
	struct s_tetra_list	*prev;
}				t_tetra_list;

t_tetra_list	*g_temp = NULL;
char			*g_line = NULL;
void			final_message(t_tetra_list **f, char exit_flag);
int				read_input(int fd, t_tetra_list *node[26]);
t_tetra_list	*add_tetra_0(void);
void			solve(t_tetra_list **first_node, t_tetra_list **last_node, int num);
void			tetra_lstdel(t_tetra_list **alst);
char			is_valid(t_tetra_list *first_node, t_tetra_list *last_node);
int				findmax_tetra_size(t_tetra_list *f);
int				findmin_tetra_pos(t_tetra_list *f);
t_tetra_list	*add_tetra(t_tetra_list **prev);
void			add_tetra_type_x(signed int x0, signed int x1,
signed int x2, signed int x3);
void			add_tetra_type_y(signed int y0, signed int y1,
signed int y2, signed int y3);
void			init_this_tetra_pos(t_tetra_list **temp);
void			set_tetra_pos(int pos_x, int pos_y, t_tetra_list **node);
void			inc_tetra_pos_x(t_tetra_list **node);
void			inc_tetra_pos_y(t_tetra_list **node);
char			help_norme5(char *flag, t_tetra_list **f, int i, int j);
void			print_composition(t_tetra_list **f, int square_size,
char c_copy);
int				solve_last_node(t_tetra_list **first_node, t_tetra_list
**last_node, int square_size);
int				solve_middle_node(t_tetra_list **first_node, t_tetra_list
**middle_node, t_tetra_list **last_node, int square_size);
void			solve_first_node(t_tetra_list **first_node, t_tetra_list
**last_node, int square_size);
int				ft_sqrt(int nb);
char			findmin_square_size(int n);
int				help_norme4(int i, int j, t_tetra_list *tetra, int flag[2]);
int				check_tetra(t_tetra_list *tetra);
void			input_tetra(int type_x[4], int type_y[4], t_tetra_list **node);
void			help_norme3(int type_x[5], int type_y[5], t_tetra_list *node[26],
int num[2]);
void			help_norme2(int type_x[5], int type_y[5], t_tetra_list *node[26],
int num[2]);

#endif
