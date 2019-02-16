/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:29:26 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/14 15:29:26 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

void	print_stack(t_stacks ab)
{
	int i = ab.a_top;
	int j = ab.b_top;
	int x = -1;

	while (++x < ab.num)
	{
		if (i == ab.a_top && i > -1 && ab.a_num > 0)
			ft_printf("%{RED ->%5d", ab.a[i]);
		else if (x >= ab.a_num)
		    ft_printf("%{RED %7c", '_');
		else
			ft_printf("%{RED %7d%", ab.a[i]);
		if (ab.b_top == j && j > -1 && ab.b_num > 0)
			ft_printf("%{YELLOW %7d    <-%} \n", ab.b[j]);
		else if (x >= ab.b_num)
			ft_printf("%{YELLOW %7c%} \n", '_');
		else
			ft_printf("%{YELLOW %7d%} \n", ab.b[j]);
		if (i == ab.num - 1 && x < ab.a_num)
			i = -1;
		if (j == ab.num - 1 && x < ab.b_num)
			j = -1;
		i++;
		j++;
	}
}
