/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:58:43 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/19 10:58:45 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_main_even(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab);
		}
		else
		{
			f++;
			do_rb(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rrb(ab, f);
}

void	push_a_main_uneven(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top + 1) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab);
		}
		else
		{
			f++;
			do_rb(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rrb(ab, f);
}

void	push_a_secondary_even(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab);
		}
		else
		{
			f++;
			do_rb(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rrb(ab, f);
}

void	push_a_secondary_uneven(t_stacks *ab, t_sorted srtd, int med)
{
	const int	difference = (srtd.bot - srtd.top + 1) / 2;
	int			count;
	int			f;

	count = 0;
	f = 0;
	while (count < difference)
	{
		if (ab->b[ab->b_top] > med)
		{
			count++;
			do_pa(ab);
		}
		else
		{
			f++;
			do_rb(ab, 0);
		}
//		print_stack(*ab);
	}
	many_rrb(ab, f);
}