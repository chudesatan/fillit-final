/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:38:58 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/03/08 15:39:02 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int				fd;
	int				num;
	t_tetra_list	*node[26];

	g_temp = NULL;
	g_line = NULL;
	if (argc == 1)
		final_message(NULL, 1);
	if ((fd = open(argv[1], O_RDWR)) == -1)
		final_message(NULL, 1);
	num = 0;
	node[num] = add_tetra_0();
	num = read_input(fd, node);
	close(fd);
	solve(&node[0], &node[num], num);
}
