/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:20:03 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/12 17:52:45 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CHECKER_H
#define FT_PRINTF_CHECKER_H

# define A_BOT (ab->a_num - ab->num + ab->a_top)
# define A_BOT_2 (ab->a_top + ab->a_num)
# define B_BOT (ab->b_num - ab->num + ab->b_top)
# define B_BOT_2 (ab->b_top + ab->b_num)
# define FREE_A_B ft_memdel((void **)&(ab.b)); ft_memdel((void **)&(ab.b));
# define CH_ERR(x) if((x) == 1) {FREE_A_B; return(1);}

# include "../ft_printf/ft_printf.h"

typedef struct		s_stacks
{
	int *a;
	int *b;
	int a_top;
	int b_top;
	int a_num;
	int b_num;
	int num;
}					t_stacks;

int			checker(int num, const char **data);
int			check_args(int num, const char **data);
int			init_a_b_stacks(t_stacks *ab, int num, const char **data);
int			do_oper(t_stacks *ab, char oper[]);
int			do_sa(t_stacks *ab);
int			do_sb(t_stacks *ab);
int			do_ss(t_stacks *ab);
int			do_pa(t_stacks *ab);
int			do_pb(t_stacks *ab);
int			do_ra(t_stacks *ab);
int			do_rb(t_stacks *ab);
int			do_rr(t_stacks *ab);
int			do_rra(t_stacks *ab);
int			do_rrb(t_stacks *ab);
int			do_rrr(t_stacks *ab);
long int	ft_atoli(const char *str);
int			get_next_line(const int fd, char **line);

#endif