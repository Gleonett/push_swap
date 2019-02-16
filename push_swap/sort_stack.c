/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:07:59 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/16 17:47:29 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int mediana(t_sorted srtd, int *mediana, int *main_med, int *flag)
{
	int num;
	static int count_main_mediana;

	if (srtd.top >= srtd.bot - 1)
	{
        *flag = 1;
        return (1);
    }
	num = (srtd.bot - srtd.top) / 2 + srtd.top;
	*mediana = srtd.sorted[num];
//    if (count_main_mediana == 1 && *mediana < *main_med)
//    {
//        *flag = 0;
//        count_main_mediana++;
//    }
    if (*flag == 2)
    {
        *main_med = *mediana;
        count_main_mediana++;
        *flag = 0;
    }
	return (0);
}

t_sorted init_sorted(t_sorted srtd, int med, int main_med, int flag)
{
    if (med >= main_med)
    {
        if (flag == 0)
            srtd.bot /= 2;
        else
            srtd.top += ((srtd.bot - srtd.top) / 2);
        return (srtd);
    }
    else
    {
        if (flag == 0)
            srtd.top += ((srtd.bot - srtd.top) / 2);
        else
            srtd.bot = srtd.bot / 2;
        return (srtd);
    }
}

int 	q_sort_stack(t_stacks *ab, t_sorted srtd, int main_med, int *flag)
{
	int count;
	int med;
	int f = 0;

	count = 0;
	CHECK_END (mediana(srtd, &med, &main_med, flag))
	if (med >= main_med)
	{
        if (*flag == 0)
            while (count < srtd.bot - srtd.top)
            {
                if (ab->a[ab->a_top] < med)
                    do_pb(ab);
                else
                    do_ra(ab, 0);
                count++;
            }
        else
            while (count < srtd.bot - srtd.top)
            {
                if (ab->b[ab->b_top] > srtd.sorted[srtd.bot + f])
                {
                    do_pa(ab);
                    f++;
                }
                if (ab->b[ab->b_top] >= med)
                    do_rrb(ab, 0);
                else
                    do_sb(ab, 0);
                count++;
            }
    }
//    else
//    {
//        if (*flag == 0)
//        {
//            f = 0;
//            while (count < (srtd.bot - srtd.top - 1))
//            {
//                ft_printf("[%d]  [%d]\n", ab->b[ab->b_top], srtd.sorted[srtd.bot - f]);
//                if (ab->b[ab->b_top] <= med)
//                {
//                    do_rb(ab, 0);
//                }
//                else if (ab->b[ab->b_top] == srtd.sorted[srtd.bot - f])
//                {
//                    do_pa(ab);
//                    f++;
//                    count++;
//                }
//                else
//                {
//                    do_sb(ab, 0);
//                }
//                print_stack(*ab);
//            }
//        }
//        else
//            while (count < srtd.bot - srtd.top)
//            {
//                if (ab->b[ab->b_top] > srtd.sorted[srtd.bot + f])
//                {
//                    do_pa(ab);
//                    f++;
//                }
//                else if (ab->b[ab->b_top] <= med)
//                {
//                    do_rb(ab, 0);
//                }
//                else
//                    do_sb(ab, 0);
//                count++;
//            }
//    }
	print_stack(*ab);
    ft_printf("left = [%d]\n", med);
	q_sort_stack(ab, init_sorted(srtd, med, main_med, 1), main_med, flag);
	if (med == main_med)
    {
	    f = 2;
	    count = 0;
        while (count < (srtd.bot / 2))
        {
            if (ab->b[ab->b_top] == srtd.sorted[srtd.bot - f])
            {
                do_pa(ab);
                f++;
            }
            else if (ab->b[ab->b_top] < med)
                do_rrb(ab, 0);
            else
                do_sb(ab, 0);
            count++;
            print_stack(*ab);
        }
        *flag = 0;
    }
	ft_printf("right = [%d]\n", med);
	q_sort_stack(ab, init_sorted(srtd, med, main_med, 0), main_med, flag);
	if (med < main_med)
	{
		f = 0;
		while (count < (srtd.bot - srtd.top))
		{
			ft_printf("[%d]  [%d]\n", ab->b[ab->b_top], srtd.sorted[srtd.bot - f]);
			if (ab->b[ab->b_top] < med)
			{
				do_rb(ab, 0);
			}
			else if (ab->b[ab->b_top] == srtd.sorted[srtd.bot - f])
			{
				do_pa(ab);
				f++;
				count++;
			}
			else
			{
				do_sb(ab, 0);
			}
			print_stack(*ab);
		}
	}
	else
		while (count < srtd.bot - srtd.top)
		{
			if (ab->b[ab->b_top] > srtd.sorted[srtd.bot + f])
			{
				do_pa(ab);
				f++;
			}
			else if (ab->b[ab->b_top] <= med)
				{
					do_rb(ab, 0);
				}
				else
					do_sb(ab, 0);
			count++;
		}
    ft_printf("exit = [%d]\n", med);
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
	srtd.top = 0;
	srtd.bot = ab->num;
//	lol = init_sorted(srtd, 1);
//	mediana(srtd, &med);
//	ft_printf("%d\n%d", lol.top, lol.bot);
	q_sort_stack(ab, srtd, 0, &flag);
    ft_printf("%d %d %d %d %d %d %d %d %d %d\n", sorted[0], sorted[1],
              sorted[2], sorted[3], sorted[4], sorted[5], sorted[6], sorted[7],
              sorted[8], sorted[9]);
    while (ab->b_num != 0)
    {
        ft_printf("[%d]  [%d]\n", srtd.sorted[srtd.top + ab->b_num - 1], ab->b[ab->b_top]);
        if (srtd.sorted[srtd.top + ab->b_num - 1] != ab->b[ab->b_top])
            do_rb(ab, 0);
        else
            do_pa(ab);
        print_stack(*ab);
    }
    do_pa(ab);
    print_stack(*ab);
    return (0);
}
