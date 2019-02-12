/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:31:40 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/12 17:52:45 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

int do_oper(t_stacks *ab, char oper[])
{
	static int a_head;

	if (ft_strcmp(oper, "sa") == 0)
		return (do_sa(ab));
	else if (ft_strcmp(oper, "sb") == 0)
		return (do_sb(ab));
	else if (ft_strcmp(oper, "ss") == 0)
		return (do_ss(ab));
	else if (ft_strcmp(oper, "pa") == 0)
		return (do_pa(ab));
	else if (ft_strcmp(oper, "pb") == 0)
		return (do_pb(ab));
	else if (ft_strcmp(oper, "ra") == 0)
		return (do_ra(ab));
	else if (ft_strcmp(oper, "rb") == 0)
		return (do_rb(ab));
	else if (ft_strcmp(oper, "rr") == 0)
		return (do_rr(ab));
	else if (ft_strcmp(oper, "rra") == 0)
		return (do_rra(ab));
	else if (ft_strcmp(oper, "rrb") == 0)
		return (do_rrb(ab));
	else if (ft_strcmp(oper, "rrr") == 0)
		return (do_rrr(ab));
	return (1);
}
