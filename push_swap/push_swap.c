/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:38:51 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 16:07:55 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arr(t_stacks ab)
{
	int i;
	int j;

	if (ab.a_top + 1 >= ab.num)
	{
		i = 0;
		j = ab.a_top;
	}
	else
	{
		i = ab.a_top + 1;
		j = ab.a_top;
	}
	while (i != ab.a_top)
	{
		if (ab.a[i] <= ab.a[j])
			return (2);
		j = i;
		if (++i == ab.num)
			i = 0;
	}
	return (0);
}

int			push_swap(int num, const char **args)
{
	t_stacks ab;
	int *sorted;
	int ret;

	if (check_args(num, args) != 0)
		return (1);
	CH_ERR_FREE(init_a_b_stacks(&ab, num, args) != 0);
	CH_SORTED(sorted = pre_sort(ab));
	sort_stack(&ab, sorted);
//	print_stack(ab);
	ret = check_arr(ab);
	ft_memdel((void **)(&(ab.a)));
	ft_memdel((void **)(&(ab.b)));
	ft_memdel((void **)&sorted);
	return (ret);
}
