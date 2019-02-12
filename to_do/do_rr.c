/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:31:39 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/12 17:51:15 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int do_rra(t_stacks *ab)
{
	int a_bot;

	if (ab->a_num < 2)
		return (0);
	ft_printf("%d %d %d %d\n", ab->a[0], ab->a[1], ab->a[2], ab->a[3]);
	if (ab->a_top + ab->a_num > ab->num)
	{
		a_bot = ab->a_top + ab->a_num - ab->num - 1;
	}
	else
		a_bot = ab->a_top + ab->a_num - 1;
	if ((ab->a_top -= 1) == -1)
		ab->a_top = ab->num - 1;
	ab->a[ab->a_top] = ab->a[a_bot];
	return (0);
}

int do_rrb(t_stacks *ab)
{
	int b_bot;

	if (ab->b_num < 2)
		return (0);
	if (ab->b_top + ab->b_num > ab->num)
		b_bot = ab->b_top + ab->b_num - ab->num - 1;
	else
		b_bot = ab->b_top + ab->b_num - 1;
	if ((ab->b_top -= 1) == -1)
		ab->b_top = ab->num - 1;
	ab->b[ab->b_top] = ab->b[b_bot];
	return (0);
}

int do_rrr(t_stacks *ab)
{
	do_rra(ab);
	do_rrb(ab);
	return (0);
}
