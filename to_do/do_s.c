/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:58:00 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/11 16:43:39 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int do_sa(t_stacks *ab)
{
	if (ab->a_num < 2)
		return (0);
	ft_swap_int(ab->a + ab->a_top, ab->a + ab->a_top + 1);
	return (0);
}

int do_sb(t_stacks *ab)
{
	if (ab->b_num < 2)
		return (0);
	ft_swap_int(ab->b + ab->b_top, ab->b + ab->b_top + 1);
	return (0);
}

int do_ss(t_stacks *ab)
{
	do_sa(ab);
	do_sb(ab);
	return (0);
}