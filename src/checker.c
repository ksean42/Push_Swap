/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:01:44 by ksean             #+#    #+#             */
/*   Updated: 2020/08/15 18:08:20 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_ko(t_stack *stack_a, t_stack *stack_b)
{
	ft_free(stack_a);
	ft_free(stack_b);
	ft_putendl("KO");
	exit(0);
}

void	exit_ok(t_stack *stack_a, t_stack *stack_b)
{
	ft_free(stack_a);
	ft_free(stack_b);
	ft_putendl("OK");
	exit(0);
}

void	exit_with_error(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (op)
		free(op);
	ft_free(stack_a);
	ft_free(stack_b);
	ft_putendl("Error");
	exit(-1);
}

void	move(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strequ("sa", op))
		sx(stack_a, NULL);
	else if (ft_strequ("sb", op))
		sx(stack_b, NULL);
	else if (ft_strequ("ss", op))
		ss(stack_a, stack_b, 0);
	else if (ft_strequ("pa", op))
		px(stack_a, stack_b, NULL);
	else if (ft_strequ("pb", op))
		px(stack_b, stack_a, NULL);
	else if (ft_strequ("ra", op))
		rx(stack_a, NULL);
	else if (ft_strequ("rb", op))
		rx(stack_b, NULL);
	else if (ft_strequ("rr", op))
		rr(stack_a, stack_b, 0);
	else if (ft_strequ("rra", op))
		rrx(stack_a, NULL);
	else if (ft_strequ("rrb", op))
		rrx(stack_b, NULL);
	else if (ft_strequ("rrr", op))
		rrr(stack_a, stack_b, 0);
	else
		exit_with_error(*stack_a, *stack_b, op);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;
	int		ret;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (validation(&stack_a, argv, argc - 1) && check_dups(stack_a))
	{
		while ((ret = get_next_line(0, &op)) > 0)
		{
			if (ret == -1)
				exit_with_error(stack_a, stack_b, op);
			move(&stack_a, &stack_b, op);
			free(op);
		}
		if (is_sorted(&stack_a) && !stack_b)
			exit_ok(stack_a, stack_b);
		else
			exit_ko(stack_a, stack_b);
	}
	exit_with_error(stack_a, stack_b, NULL);
	return (0);
}
