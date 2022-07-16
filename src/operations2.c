/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 03:37:29 by ksean             #+#    #+#             */
/*   Updated: 2020/08/10 22:43:34 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, int v)
{
	if (stack_a)
		rx(stack_a, NULL);
	if (stack_b)
		rx(stack_b, NULL);
	if (v == 1)
		ft_putendl("rr");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int v)
{
	if (stack_a)
		rrx(stack_a, NULL);
	if (stack_b)
		rrx(stack_b, NULL);
	if (v == 1)
		ft_putendl("rrr");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int v)
{
	if (stack_a)
		sx(stack_a, NULL);
	if (stack_b)
		sx(stack_b, NULL);
	if (v == 1)
		ft_putendl("ss");
}

void	rx_both(t_stack **stack_a, t_stack **stack_b,
		int *ra_count, int *rb_count)
{
	while (*ra_count != 0 && *rb_count != 0)
	{
		rr(stack_a, stack_b, 1);
		*ra_count -= 1;
		*rb_count -= 1;
	}
	while (*ra_count != 0)
	{
		rx(stack_a, "ra");
		*ra_count -= 1;
	}
	while (*rb_count != 0)
	{
		rx(stack_b, "rb");
		*rb_count -= 1;
	}
}

void	rrx_both(t_stack **stack_a, t_stack **stack_b,
		int *ra_count, int *rb_count)
{
	while (*ra_count != 0 && *rb_count != 0)
	{
		rrr(stack_a, stack_b, 1);
		*ra_count += 1;
		*rb_count += 1;
	}
	while (*ra_count != 0)
	{
		rrx(stack_a, "rra");
		*ra_count += 1;
	}
	while (*rb_count != 0)
	{
		rrx(stack_b, "rrb");
		*rb_count += 1;
	}
}
