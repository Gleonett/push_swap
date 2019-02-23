/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:15:06 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/22 15:15:07 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_stack_a(t_stacks *ab, t_sorted sorted, int i)
{
	int j;
	int f;

	j = 0;
	f = 0;
//	print_stack(*ab);
	while (i >= sorted.top)
	{
//		ft_printf("[%d] [%d]\n", ab->a[ab->a_top], sorted.sorted[i]);
		if (ab->a[ab->a_top] != sorted.sorted[i])
		{
			do_ra(ab, 1);
			j++;
			f++;
		}
		else
		{
			do_ra(ab, 1);
			j++;
		}
		i--;
//				print_stack(*ab);
	}
	many_rra(ab, j, 1);
	return (f);
}

static void	sort_a(t_stacks *ab, t_sorted sorted)
{
	const int start = A_PREV;
	int i;
	int j;

	i = sorted.bot - 1;
	j = 0;
	print_stack(*ab);
	while (i >= sorted.top)
	{
		while (ab->a[ab->a_top] > ab->a[A_NEXT])
		{
			//			ft_printf("[%d] [%d]\n", ab->a[ab->a_top], ab->a[A_NEXT]);
			//			print_stack(*ab);
			do_sa(ab, 0);
			if (ab->a[ab->a_top] < ab->a[A_PREV] && A_PREV != start)
			{
				do_rra(ab, 0);
				j--;
				i++;
			}
			//			print_stack(*ab);
		}
		//		ft_printf("[%d] [%d]\n", ab->a[ab->a_top], ab->a[A_NEXT]);
				print_stack(*ab);
		if (check_stack_a(ab, sorted, i) == 0)
			break ;
		do_ra(ab, 0);
		j++;
				print_stack(*ab);
		i--;
	}
	many_rra(ab, j, 0);
	print_stack(*ab);
}

static int check_stack_b(t_stacks *ab, t_sorted sorted, int i, int *k)
{
	const int start_k = *k;
	int j;
	int f;

	j = 0;
	f = 0;

	many_rrb(ab, *k, 1);
	*k = 0;
	while (i < sorted.bot)
	{
//		ft_printf("[%d] [%d]\n", ab->b[ab->b_top], sorted.sorted[i]);
		if (ab->b[ab->b_top] != sorted.sorted[i])
		{
			*k == 0 ? *k = j : 0;
			do_rb(ab, 1);
			j++;
			f++;
		}
		else
		{
			do_rb(ab, 1);
			j++;
		}
		i++;
//		print_stack(*ab);
	}
	*k != 0 ? *k = j - *k : 0;
	start_k == 0 ? *k = 0 : 0;
	many_rrb(ab, j, 1);
	return (f);
}

static void	sort_b(t_stacks *ab, t_sorted sorted)
{
	const int start = B_PREV;
	int i;
	int j;
	int k;

	i = sorted.top;
	j = 0;
	k = 0;
	while (i < sorted.bot)
	{
		while (ab->b[ab->b_top] < ab->b[B_NEXT] && i > 0)
		{
//			ft_printf("[%d] [%d]\n", ab->b[ab->b_top], ab->b[B_NEXT]);
			print_stack(*ab);
			do_sb(ab, 0);
			if (ab->b[ab->b_top] > ab->b[B_PREV])
			{
				do_rb(ab, 0);
				j--;
				i--;
				k++;
			}
			//			print_stack(*ab);
		}
//		ft_printf("[%d] [%d]\n", ab->b[ab->b_top], ab->b[B_NEXT]);
		print_stack(*ab);
		if (check_stack_b(ab, sorted, i, &k) == 0)
			break ;
		k != 0 ? many_rrb(ab, k, 0), j -= k, k = 0 : do_rb(ab, 0);
		j++;
		//		print_stack(*ab);
		i++;
	}
	many_rrb(ab, j, 0);
}

int	insertion_sort(t_stacks *ab, t_sorted sorted, int aorb)
{
	const int k = 0;
	t_stacks *cpy;

	cpy = cpy_stacks(ab);
	if (sorted.bot - sorted.top < 4)
		return (0);
	if (aorb == 1)
	{
		if (check_stack_a(cpy, sorted, sorted.bot - 1) > 4)
			return (0);
		else
			sort_a(ab, sorted);
	}
	else
	{
		if (check_stack_b(cpy, sorted, sorted.top, &k) > 4)
			return (0);
		else
			sort_b(ab, sorted);
	}
	del_stacks(&cpy);
	return (1);
}