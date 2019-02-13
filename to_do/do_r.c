/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:57:02 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 13:13:34 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int	do_ra(t_stacks *ab)
{
	int a_bot;

	if (ab->a_num < 2)
		return (0);
	if (ab->a_top + ab->a_num >= ab->num)
		a_bot = ab->a_top + ab->a_num - ab->num;
	else
		a_bot = ab->a_top + ab->a_num;
	ab->a[a_bot] = ab->a[ab->a_top];
	if ((ab->a_top += 1) == ab->num)
		ab->a_top = 0;
	return (0);
}

int	do_rb(t_stacks *ab)
{
	int b_bot;

	if (ab->b_num < 2)
		return (0);
	if (ab->b_top + ab->b_num >= ab->num)
		b_bot = ab->b_top + ab->b_num - ab->num;
	else
		b_bot = ab->b_top + ab->b_num;
	ab->b[b_bot] = ab->b[ab->b_top];
	if ((ab->b_top += 1) == ab->num)
		ab->b_top = 0;
	return (0);
}

int	do_rr(t_stacks *ab)
{
	do_ra(ab);
	do_rb(ab);
	return (0);
}
