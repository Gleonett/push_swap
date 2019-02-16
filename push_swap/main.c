/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:24:14 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/16 13:42:30 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int res;

	if (argc < 2)
		return (1);
	if ((res = push_swap(argc - 1, (const char **)argv + 1)) == 1)
		ft_printf("%{PURPLE Error\n");
	else if (res == 0)
		ft_printf("%{GREEN OK\n");
	else
		ft_printf("%{RED KO\n");
	return (0);
}
