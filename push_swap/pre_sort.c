/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:03:59 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/16 20:31:21 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pre_sort(t_stacks ab)
{
	int *sorted;
	int i;

	if ((sorted = (int *)malloc(sizeof(int) * ab.num)) == NULL)
		return (NULL);
	ft_memcpy(sorted, ab.a, sizeof(int) * ab.num);
	ft_recursiv_shells_sort(sorted, ab.num - 1, ab.num / 2);
	ft_printf("%d %d %d %d %d %d %d %d %d %d\n", sorted[0], sorted[1],
			sorted[2], sorted[3], sorted[4], sorted[5], sorted[6], sorted[7],
			sorted[8], sorted[9]);
	i = -1;
	while (++i <= ab.num - 1 - i)
		ft_swap_int(sorted + i, sorted + (ab.num - 1 - i));
	ft_printf("%d %d %d %d %d %d %d %d %d %d\n", sorted[0], sorted[1],
			  sorted[2], sorted[3], sorted[4], sorted[5], sorted[6], sorted[7],
			  sorted[8], sorted[9]);
	return (sorted);
}