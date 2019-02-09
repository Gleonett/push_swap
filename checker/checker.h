/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:20:03 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/08 19:47:36 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CHECKER_H
#define FT_PRINTF_CHECKER_H

# include "../ft_printf/ft_printf.h"

typedef struct		s_stack
{
	long int		num;
	struct s_stack	*next;
}					t_stack;

t_stack	*g_a_stack;
t_stack	*g_b_stack;

int			checker(int num_d, char **data);
int			check_args(int num, char **data);
int			init_a_stack(int num, char **args);
int			init_b_stack(int num);
t_stack		*stack_new(long int num);
void		stack_del(t_stack **stack);

#endif