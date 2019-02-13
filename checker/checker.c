/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:23:43 by gleonett          #+#    #+#             */
/*   Updated: 2019/02/13 13:59:28 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static const int c = 11;

static void	print_stack(t_stacks ab)
{
	int i = ab.a_top;
	int j = ab.b_top;
	int x = -1;

	while (++x < ab.num)
	{
		if (i == ab.a_top && i > -1 && ab.a_num > 0)
			ft_printf("%{RED ->%5d", ab.a[i]);
		else if (x >= ab.a_num)
			ft_printf("%{RED %7c", '_');
		else
			ft_printf("%{RED %7d%", ab.a[i]);
		if (ab.b_top == j && j > -1 && ab.b_num > 0)
			ft_printf("%{YELLOW %7d    <-%} \n", ab.b[j]);
		else if (x >= ab.b_num)
			ft_printf("%{YELLOW %7c%} \n", '_');
		else
			ft_printf("%{YELLOW %7d%} \n", ab.b[j]);
		if (i == ab.num - 1 && x < ab.a_num)
			i = -1;
		if (j == ab.num - 1 && x < ab.b_num)
			j = -1;
		i++;
		j++;
	}
}

int			check_arr(t_stacks ab)
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
	ft_printf("%d %d %d %d %d\n", ab.a[0], ab.a[1], ab.a[2], ab.a[3], ab.a[4]);
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

int			checker(int num, const char **args)
{
	t_stacks ab;
	int ret;
//	int fd;

//	char oper[c][4] = {"pb", "pb", "ss", "pb", "pb", "pa", "pa", "pa", "pa"};
//	char oper[c][4] = {"pb", "pb", "pb", "pb", "rb", "rb", "rb", "rb", "rb"};
	char oper[c][4] = {"rra", "sa", "sa", "sa", "sa", "ra"};
//	char oper[c][4] = {"pb", pb", "pb", "pb", "pb", "rrb", "rrb", "rrb",
//	"rrb",
//					"rrb", "rrb", "rrb", "rrb", "rrb", "rrb", "ra"};
	if (check_args(num, args) != 0)
		return (1);
	CH_ERR(init_a_b_stacks(&ab, num, args) != 0);
//	fd = open("test", O_RDONLY);
//	while (get_next_line(fd, &oper) > 0)
	print_stack(ab);
	int i = -1;
	while (++i < c)
	{
		do_oper(&ab, oper[i]);
		ft_printf("%{BLACK %s\n", oper[i]);
		print_stack(ab);
//		ft_memdel((void **)&oper);
	}
	ret = check_arr(ab);
	ft_memdel((void **)(&(ab.a)));
	ft_memdel((void **)(&(ab.b)));
//	close(fd);
	return (ret);
}
