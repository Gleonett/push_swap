/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:09:04 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/08 17:26:48 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

static int check_arg(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i] != '\0' && arg[i] >= '0' && arg[i] <= '9')
		i++;
	if (arg[i] != '\0')
		return (1);
	return (0);
}

int check_args(int num, char **data)
{
	int i;

	i = -1;
	while (++i < num)
		if (check_arg(data[i]) != 0)
			return (1);
	return (0);
}