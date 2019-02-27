/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:09:04 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/11 16:43:39 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

static int check_arg(const char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] && arg[i] >= '0' && arg[i] <= '9')
		i++;
	if (arg[i] != '\0' || i > 12 ||
		(i == 1 && (arg[i - 1] == '-' || arg[i - 1] == '+')))
		return (1);
	return (0);
}

int check_args(int num, const char **data)
{
	int i;

	i = -1;
	while (++i < num)
		if (check_arg(data[i]) != 0)
			return (1);
	return (0);
}