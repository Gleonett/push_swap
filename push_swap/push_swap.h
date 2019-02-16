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
# define STCK_NXT(x) if (ab->a_top + 1 == ab->num) {x = 0;} else {x = ab->a_top + 1;}
# define CH_ERR(x) if((x) == 1) {FREE_A_B; return(1);}

# include "../ft_printf/ft_printf.h"
# include "../checker/checker.h"

typedef struct	s_sorted
{
	int *sorted;
	int top;
	int bot;
}				t_sorted;

int			push_swap(int num, const char **args);
int			*pre_sort(t_stacks ab);
int			sort_stack(t_stacks *ab, int *sorted);
void		print_stack(t_stacks ab);

#endif
