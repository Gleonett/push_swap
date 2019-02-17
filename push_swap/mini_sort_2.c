/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:49:36 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/17 16:49:39 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_b_1(t_stacks *ab, t_sorted sorted)
{
	if (sorted.sorted[sorted.top] == ab->b[ab->b_top])
	{
		do_pa(ab);
		if (sorted.sorted[sorted.top + 1] != ab->b[ab->b_top])
			do_sb(ab, 0);
		many_pa(ab, 2);
	}
	else if (sorted.sorted[sorted.top + 1] == ab->b[ab->b_top])
	{
		if (ab->b[B_NEXT] == sorted.sorted[sorted.top])
		{
			do_sb(ab, 0);
			many_pa(ab, 3);
		}
		else
		{
			do_rb(ab, 0);
			do_sb(ab, 0);
			do_pa(ab);
			do_rrb(ab, 0);
			many_pa(ab, 2);
		}
	}
	else
	{
		ab->b[B_NEXT] != sorted.sorted[sorted.top] ?
			do_rrb(ab, 0) : do_sb(ab, 0);
		do_pa(ab);
		if (sorted.sorted[sorted.top + 1] != ab->b[ab->b_top])
			do_sb(ab, 0);
		many_pa(ab, ab->b_num);
	}
}