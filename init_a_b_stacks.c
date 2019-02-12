/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_b_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:51:20 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/11 18:42:54 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

int			init_a_b_stacks(t_stacks *ab, int num, const char **data)
{
	int i;
	long int buf;

	CH_NULL(ab->a = (int *)ft_memalloc(sizeof(int) * num));
	i = -1;
	while (++i < num)
	{
		if ((buf = ft_atoli(data[i])) < -2147483648 || buf > 2147483647)
		{
			ft_memdel((void **)&(ab->a));
			return (1);
		}
		ab->a[i] = (int)buf;
	}
	CH_NULL(ab->b = (int *)ft_memalloc(sizeof(int) * num));
	ab->num = num;
	ab->a_top = 0;
	ab->b_top = num;
	ab->a_num = num;
	ab->b_num = 0;
	return (0);
}