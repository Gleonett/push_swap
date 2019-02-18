/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:07:59 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/17 13:32:55 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int mediana(t_sorted srtd, int *mediana, int *main_med, int *flag)
{
	int num;

	if (srtd.top >= srtd.bot)
	{
        *flag = 1;
        *mediana = srtd.sorted[srtd.top];
        return (1);
    }
	num = (srtd.bot - srtd.top) / 2 + srtd.top;
	*mediana = srtd.sorted[num];
    if (*flag == 2)
    {
        *main_med = *mediana;
        *flag = 0;
    }
	return (0);
}

t_sorted init_sorted(t_sorted srtd, int med, int main_med, int flag)
{
	static int count_recurs;

        if (flag == 1)
			srtd.bot /= 2;
        else
			srtd.top += ((srtd.bot - srtd.top) / 2);
        count_recurs++;
    srtd.flag = flag;
	return (srtd);
}

int 	q_sort_stack(t_stacks *ab, t_sorted srtd, int main_med, int *flag)
{
	int count;
	int med;
	int f = 0;

	count = 0;
	if (mediana(srtd, &med, &main_med, flag) == 1)
	{
		if (med >= main_med)
		{
			if (ab->a[ab->a_top] >= med && ab->a_num == 2)
				do_sa(ab, 0);
			ft_printf("[%d]  [%d]\n", ab->b[ab->b_top], ab->b[ab->b_top + 1]);
			if (srtd.flag == 1 && ab->b[ab->b_top] < ab->b[ab->b_top + 1 ==
					ab->num ? 0 : ab->b_top + 1])
				do_sb(ab, 0);
			do_pa(ab);
			print_stack(*ab);
			return (1);
		}
	}
	if (med >= main_med)
	{
        if (*flag == 0)
            while (count < (srtd.bot - srtd.top) / 2)
            {
                if (ab->a[ab->a_top] <= med)
				{
					count++;
					do_pb(ab);
				}
                else
                    do_ra(ab, 0);
				print_stack(*ab);
            }
		print_stack(*ab);
    }
	else
	{
		if (*flag == 0)
			while (count < (srtd.bot - srtd.top) / 2)
			{
				if (ab->b[ab->b_top] >= med)
				{
					count++;
					do_pa(ab);
				}
				else
					do_rb(ab, 0);
				print_stack(*ab);
			}
	}
	print_stack(*ab);
//    ft_printf("left = [%d]\n", med);
	q_sort_stack(ab, init_sorted(srtd, med, main_med, 1), main_med, flag);
	if (med == main_med)
	{
		*flag = 0;
	}
//	ft_printf("right = [%d]\n", med);
	q_sort_stack(ab, init_sorted(srtd, med, main_med, 0), main_med, flag);
//    ft_printf("exit = [%d]\n", med);
	return (0);
}

int	sort_stack(t_stacks *ab, int *sorted)
{
	t_sorted srtd;
	t_sorted lol;
	int med;
	int flag;

	flag = 2;
	srtd.sorted = sorted;
	srtd.top = 1;
	srtd.bot = ab->num;
	srtd.flag = 0;
//	lol = init_sorted(srtd, 1);
//	mediana(srtd, &med);
//	ft_printf("%d\n%d", lol.top, lol.bot);
//	q_sort_stack(ab, srtd, 0, &flag);
//	do_pb(ab);
//	do_pb(ab);
//	do_pb(ab);
//	do_pb(ab);
	ft_printf("------------------------------------\n");
	mini_sort(ab, srtd, 0, 1);
	ft_printf("------------------------------------\n");
    ft_printf("%d %d %d %d %d %d %d %d %d %d\n", sorted[0], sorted[1],
              sorted[2], sorted[3], sorted[4], sorted[5], sorted[6], sorted[7],
              sorted[8], sorted[9]);
	print_stack(*ab);
    return (0);
}
