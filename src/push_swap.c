/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:38:56 by ksean             #+#    #+#             */
/*   Updated: 2021/05/22 23:49:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int		main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (argc == 1)
		return (-1);

	if (validation(&stack_a, argv, argc - 1) && check_dups(stack_a))
	{
		if (is_sorted(&stack_a))
		{
			ft_free(stack_a);
			return (0);
		}
		solve(&stack_a, &stack_b);
		ft_free(stack_b);
		ft_free(stack_a);
		return (0);
	}

	ft_free(stack_a);
	ft_putendl("Error");
	return (-1);
}
