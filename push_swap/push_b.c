/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:35:39 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/19 10:35:41 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_main_even(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->a[ab->a_top] <= med)
		{
			count++;
			do_pb(ab);
		}
		else
		{
			f++;
			do_ra(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rra(ab, f);
}

void	push_b_main_uneven(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->a[ab->a_top] <= med)
		{
			count++;
			do_pb(ab);
		}
		else
		{
			f++;
			do_ra(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rra(ab, f);
}

void	push_b_secondary_even(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->a[ab->a_top] <= med)
		{
			count++;
			do_pb(ab);
		}
		else
		{
			f++;
			do_ra(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rra(ab, f);
}

void	push_b_secondary_uneven(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->a[ab->a_top] <= med)
		{
			count++;
			do_pb(ab);
		}
		else
		{
			f++;
			do_ra(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rra(ab, f);
}