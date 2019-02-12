/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:57:02 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/12 14:25:56 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int do_ra(t_stacks *ab)
{
	if (ab->a_num < 2)
		return (0);
	if (A_BOT < 0)
	{
		ft_swap_int(&(ab->a[ab->a_top]), &(ab->a[A_BOT_2]));
		if ((ab->a_top += 1) >= ab->num)
			ab->a_top = 0;
	}
	else
	{
		ft_swap_int(&(ab->a[ab->a_top]), &(ab->a[A_BOT]));
		if ((ab->a_top += 1) >= ab->num)
			ab->a_top = 0;
	}
	return (0);
}

int do_rb(t_stacks *ab)
{
	if (ab->b_num < 2)
		return (0);
	if (B_BOT < 0)
	{
		ft_swap_int(&(ab->b[ab->b_top]), &(ab->b[B_BOT_2]));
		if ((ab->b_top += 1) >= ab->num)
			ab->b_top = 0;
	}
	else
	{
		ft_swap_int(&(ab->b[ab->b_top]), &(ab->b[B_BOT]));
		if ((ab->b_top += 1) >= ab->num)
			ab->b_top = 0;
	}
	return (0);
}

int do_rr(t_stacks *ab)
{
	do_ra(ab);
	do_rb(ab);
	return (0);
}
