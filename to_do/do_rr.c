/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:31:39 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 13:53:27 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int	do_rra(t_stacks *ab, int flag)
{
	int a_bot;

	if (flag == 0)
        ft_putstr_full("rra\n");
	if (ab->a_num < 2)
		return (0);
	if (ab->a_top + ab->a_num > ab->num)
		a_bot = ab->a_top + ab->a_num - ab->num - 1;
	else
		a_bot = ab->a_top + ab->a_num - 1;
	if ((ab->a_top -= 1) == -1)
		ab->a_top = ab->num - 1;
	ab->a[ab->a_top] = ab->a[a_bot];
	return (0);
}

void	many_rra(t_stacks *ab, int num, int flag)
{
	while (--num > -1)
		do_rra(ab, flag == 0 ? 0 : 1);
}

int	do_rrb(t_stacks *ab, int flag)
{
	int b_bot;

	if (flag == 0)
        ft_putstr_full("rrb\n");
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

void	many_rrb(t_stacks *ab, int num, int flag)
{
	while (--num > -1)
		do_rrb(ab, flag == 0 ? 0 : 1);
}

int	do_rrr(t_stacks *ab)
{
    ft_putstr_full("rrr\n");
    do_rra(ab, 1);
    do_rrb(ab, 1);
	return (0);
}
