/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:11:08 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/11 18:29:03 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int do_pa(t_stacks *ab)
{
	if (ab->b_top == ab->num)
		return (0);
	ab->a_top -= 1;
	ab->a[ab->a_top] = ab->b[ab->b_top];
	ab->b_top += 1;
	ab->a_num += 1;
	ab->b_num -= 1;
	return (0);
}

int do_pb(t_stacks *ab)
{
	if (ab->a_top == ab->num)
		return (0);
	ab->b_top -= 1;
	ab->b[ab->b_top] = ab->a[ab->a_top];
	ab->a_top += 1;
	ab->b_num += 1;
	ab->a_num -= 1;
	return (0);
}