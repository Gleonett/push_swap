/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:29:26 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/14 15:29:26 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

static void print_changes_ab_top(int nmbr, int flag, int aorb)
{
	if (aorb == 0)
	{
		if (flag == 1 || flag == 2 || flag == 5 || flag == 4 || flag == 7)
			ft_printf(PURPLE"%7d", nmbr);
		else
			ft_printf(RED"%7d", nmbr);
	}
	else
		if (flag == 8 || flag == 9 || flag == 5 || flag == 11 || flag == 7)
			ft_printf(PURPLE"%7d\n", nmbr);
		else
			ft_printf(YELLOW"%7d\n", nmbr);
}

static void	print_changes_ab(t_stacks *ab, int i, int flag, int aorb)
{
	if (aorb == 0)
	{
		if (i == A_PREV && (flag == 3 || flag == 6))
			ft_printf(PURPLE"%7d", ab->a[i]);
		else if (i == A_NEXT && (flag == 2 || flag == 5))
			ft_printf(PURPLE"%7d", ab->a[i]);
		else
			ft_printf(RED"%7d", ab->a[i]);
	}
	else
		if (i == B_PREV && (flag == 10 || flag == 6))
			ft_printf(PURPLE"%7d\n", ab->b[i]);
		else if (i == B_NEXT && (flag == 9 || flag == 5))
			ft_printf(PURPLE"%7d\n", ab->b[i]);
		else
			ft_printf(YELLOW"%7d\n", ab->b[i]);

}

void	print_stack(t_stacks *ab, int flag)
{
	int i = ab->a_top;
	int j = ab->b_top;
	int x = -1;

	while (++x < ab->num)
	{
		if (i == ab->a_top && i > -1 && ab->a_num > 0)
			print_changes_ab_top(ab->a[i], flag, 0);
		else if (x >= ab->a_num)
		    ft_printf(RED"%7c", '_');
		else
			print_changes_ab(ab, i, flag, 0);
		if (ab->b_top == j && j > -1 && ab->b_num > 0)
			print_changes_ab_top(ab->b[j], flag, 1);
		else if (x >= ab->b_num)
			ft_printf(YELLOW"%7c\n"REBOOT, '_');
		else
			print_changes_ab(ab, j, flag, 1);
		if (i == ab->num - 1 && x < ab->a_num)
			i = -1;
		if (j == ab->num - 1 && x < ab->b_num)
			j = -1;
		i++;
		j++;
	}
	ft_putchar('\n');
}
