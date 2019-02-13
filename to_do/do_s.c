/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:58:00 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 13:52:59 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int	do_sa(t_stacks *ab)
{
	int a_second;

	if (ab->a_num < 2)
		return (0);
	if ((a_second = ab->a_top + 1) == ab->num)
		a_second = 0;
	ft_swap_int(ab->a + ab->a_top, ab->a + a_second);
	return (0);
}

int	do_sb(t_stacks *ab)
{
	int b_second;

	if (ab->b_num < 2)
		return (0);
	if ((b_second = ab->b_top + 1) == ab->num)
		b_second = 0;
	ft_swap_int(ab->b + ab->b_top, ab->b + b_second);
	return (0);
}

int	do_ss(t_stacks *ab)
{
	do_sa(ab);
	do_sb(ab);
	return (0);
}
