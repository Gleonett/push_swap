/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:58 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/08 19:40:13 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

int init_a_stack(int num, char **args)
{
	int			i;
	long int	buf;
	t_stack		*cursor;

	i = 0;
	if ((buf = ft_atoi(args[i])) > 2147483648 || buf < -2147483648)
		return (1);
	g_a_stack = stack_new(buf);
	cursor = g_a_stack;
	while (++i < num)
	{
		if ((buf = ft_atoi(args[i])) > 2147483648 || buf < -2147483648)
			return (1);
		cursor->next = stack_new(buf);
		cursor = cursor->next;
	}
	cursor->next = g_a_stack;
	return (0);
}

int			init_b_stack(int num)
{
	int			i;
	t_stack		*cursor;

	i = 0;
	g_a_stack = stack_new(0);
	cursor = g_a_stack;
	while (++i < num)
	{
		cursor->next = stack_new(0);
		cursor = cursor->next;
	}
	cursor->next = g_a_stack;
	return (0);
}