/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:23:43 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/08 18:01:03 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int checker(int num, char **args)
{
	if (check_args(num, args) != 0)
		return (1);
	if (init_a_stack(num, args) != 0)
		return (1);
	init_b_stack(num);
	stack_del(&g_a_stack);
	stack_del(&g_b_stack);
	return (0);
}