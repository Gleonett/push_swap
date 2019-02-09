/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:01:07 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/08 19:45:05 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker/checker.h"

t_stack	*stack_new(long int num)
{
	t_stack *new;

	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit(-1);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	stack_del(t_stack **stack)
{
	t_stack *cursor;
	t_stack *cursor_next;
	t_stack *cursor_start;

	cursor_start = *stack;
	cursor = cursor_start;
	while (cursor != cursor_start)
	{
		cursor_next = cursor->next;
		ft_memdel((void **)&cursor);
		cursor = cursor_next->next;
	}
}
