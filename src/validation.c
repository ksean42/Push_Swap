/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 07:36:36 by ksean             #+#    #+#             */
/*   Updated: 2021/05/22 23:49:25 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int		validation(t_stack **stack, char **argv, int argc)
{
	char	**values;
	int		i;

	while (argc != 0)
	{
		i = 0;
		if (!(values = ft_strsplit(argv[argc], ' ')))
			{
				return (0);
			}
		while (values[i])
		{
			if (!is_valid(values[i]))
			{
				free_arr(values);
				return (0);
			}
			i++;
		}
		while (i--)
			push(stack, ft_atoi(values[i]));
		free_arr(values);
		argc--;
	}
	return (1);
}

int		is_valid(char *value)
{
	long	res;
	short	neg;

	neg = 1;
	res = 0;
	if (ft_strequ(value, "-"))
		return (0);
	if (*value == '-')
	{
		neg = -1;
		value++;
	}
	while (*value)
	{
		if (!ft_isdigit(*value))
			return (0);
		res = res * 10 + (*value - '0');
		if (((res - 1) > INT32_MAX && neg == -1)
		|| (res > INT32_MAX && neg == 1))
			return (0);
		value++;
	}
	return (1);
}

int		check_dups(t_stack *stack)
{
	t_stack *first;
	t_stack *second;

	if (!stack)
		return (0);
	first = stack;
	second = stack->next;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->value == second->value)
				return (0);
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}
