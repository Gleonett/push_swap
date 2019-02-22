/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:20:03 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 18:29:23 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CHECKER_H
# define FT_PRINTF_CHECKER_H

# define FREE_A_B ft_memdel((void **)(&(ab.b))); ft_memdel((void **)(&(ab.b)));
# define CH_ERR_FREE(x) if((x) == 1) {FREE_A_B; return(1);}
# define CH_SORTED(x) if((x) == NULL) {FREE_A_B; return(1);}
# define CHECK_END(x) if(x == 1) return (0);
# include "../ft_printf/ft_printf.h"

typedef struct	s_stacks
{
	int *a;
	int *b;
	int a_top;
	int b_top;
	int a_num;
	int b_num;
	int num;
}				t_stacks;

int				checker(int num, const char **data);
int				check_args(int num, const char **data);
int				init_a_b_stacks(t_stacks *ab, int num, const char **data);
int				do_oper(t_stacks *ab, char oper[]);
int				do_sa(t_stacks *ab, int flag);
int				do_sb(t_stacks *ab, int flag);
int				do_ss(t_stacks *ab);
int				do_pa(t_stacks *ab, int flag);
int				do_pb(t_stacks *ab, int flag);
int				do_ra(t_stacks *ab, int flag);
int				do_rb(t_stacks *ab, int flag);
int				do_rr(t_stacks *ab);
int				do_rra(t_stacks *ab, int flag);
int				do_rrb(t_stacks *ab, int flag);
int				do_rrr(t_stacks *ab);
long int		ft_atoli(const char *str);
int				get_next_line(const int fd, char **line);

#endif
