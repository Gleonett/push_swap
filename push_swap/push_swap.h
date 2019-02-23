/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:27:14 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 18:04:09 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H
# define FREE_A_B ft_memdel((void **)(&(ab.b))); ft_memdel((void **)(&(ab.b)));
# define B_NEXT (ab->b_top + 1 == ab->num ? 0 : ab->b_top + 1)
# define A_NEXT (ab->a_top + 1 == ab->num ? 0 : ab->a_top + 1)
# define A_PREV_2 (ab->a_top + ab->a_num > ab->num)
# define A_PREV_3 (ab->a_top + ab->a_num - ab->num - 1)
# define A_PREV (A_PREV_2 ? A_PREV_3 : ab->a_top + ab->a_num - 1)
# define B_PREV (ab->b_top - 1 == -1 ? ab->b_num - 1 : ab->b_top - 1)
# define EVEN_NUM(x) (x % 2 == 0 ? x : x + 1)
# define CH_ERR(x) if((x) == 1) {FREE_A_B; return(1);}

# include "../ft_printf/ft_printf.h"
# include "../checker/checker.h"

typedef struct	s_sorted
{
	int *sorted;
	int top;
	int bot;
	int flag;
	int difference;
}				t_sorted;

int			push_swap(int num, const char **args);
int			*pre_sort(t_stacks ab);
int			sort_stack(t_stacks *ab, int *sorted);
int			mini_sort(t_stacks *ab, t_sorted sorted, int aorb, int flag);
int			insertion_sort(t_stacks *ab, t_sorted sorted, int aorb);
void		sort_ten(t_stacks *ab, t_sorted srtd, int med, int aorb);
void		push_a_main_even(t_stacks *ab, t_sorted srtd, int med);
void		push_a_main_uneven(t_stacks *ab, t_sorted srtd, int med);
void		push_a_secondary_even(t_stacks *ab, t_sorted srtd, int med);
void		push_a_secondary_uneven(t_stacks *ab, t_sorted srtd, int med);
void		push_b_main_even(t_stacks *ab, t_sorted srtd, int med, int flag);
void		push_b_main_uneven(t_stacks *ab, t_sorted srtd, int med, int flag);
void		push_b_secondary_even(t_stacks *ab, t_sorted srtd, int med);
void		push_b_secondary_uneven(t_stacks *ab, t_sorted srtd, int med);
void		mini_b_1(t_stacks *ab, t_sorted sorted);
void		mini_a_1(t_stacks *ab, t_sorted sorted);
int			r_or_rr(t_stacks ab, int aorb, int med, int difference);
void		many_pa(t_stacks *ab, int num);
void		many_rra(t_stacks *ab, int num, int flag);
void		many_rrb(t_stacks *ab, int num, int flag);
void		many_ra(t_stacks *ab, int num, int flag);
void		many_rb(t_stacks *ab, int num, int flag);
void		print_stack(t_stacks ab);
t_stacks	*cpy_stacks(t_stacks ab);
void		del_stacks(t_stacks **ab);

#endif
