/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 03:45:58 by ksean             #+#    #+#             */
/*   Updated: 2020/08/15 17:59:51 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack *curr;
	t_stack *bottom;

	curr = *stack;
	bottom = curr->next->next;
	if (is_sorted(stack))
		return ;
	if (curr->value > curr->next->value && curr->value < bottom->value)
		sx(stack, "sa");
	else if (curr->value > curr->next->value
	&& curr->next->value > bottom->value)
	{
		sx(stack, "sa");
		rrx(stack, "rra");
	}
	else if (curr->value > curr->next->value && curr->value > bottom->value)
		rx(stack, "ra");
	else if (curr->value < curr->next->value && curr->value < bottom->value)
	{
		sx(stack, "sa");
		rx(stack, "ra");
	}
	else
		rrx(stack, "rra");
}

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *curr_a;

	curr_a = *stack_a;
	while (curr_a->index != 3)
	{
		curr_a = curr_a->next;
		px(stack_b, stack_a, "pb");
	}
}

void	put_elem(t_stack **stack_a, t_stack **stack_b, int id, int size_b)
{
	t_stack	*b_elem;
	t_stack	*a_elem;
	int		ra_count;
	int		rb_count;
	int		size_a;

	a_elem = *stack_a;
	b_elem = *stack_b;
	size_a = a_elem->index;
	while (b_elem && b_elem->index != id)
		b_elem = b_elem->next;
	rb_count = (b_elem->index >= (size_b / 2)) ?
	(size_b - b_elem->index) : (b_elem->index * -1);
	a_elem = find_elem_to_ins(a_elem, b_elem);
	ra_count = (a_elem->index >= (size_a / 2)) ?
	(size_a - a_elem->index + 1) : ((a_elem->index - 1) * -1);
	if (ra_count > 0 && rb_count > 0)
		rx_both(stack_a, stack_b, &ra_count, &rb_count);
	else if (ra_count < 0 && rb_count < 0)
		rrx_both(stack_a, stack_b, &ra_count, &rb_count);
	shift_stacks(stack_a, stack_b, ra_count, rb_count);
	px(stack_a, stack_b, "pa");
}

void	insert(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack;
	int		stack_size;
	int		min;
	int		min_id;
	int		tmp;

	stack = *stack_b;
	stack_size = stack->index;
	min = count_ops(*stack_a, stack, stack_size);
	min_id = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (min > (tmp = count_ops(*stack_a, stack, stack_size)))
		{
			min = tmp;
			min_id = stack->index;
		}
		stack = stack->next;
	}
	put_elem(stack_a, stack_b, min_id, stack_size);
}

void	solve(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *curr_a;

	curr_a = *stack_a;
	if (curr_a->index < 3)
	{
		if (!is_sorted(stack_a))
			rx(stack_a, "ra");
		return ;
	}
	move_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		insert(stack_a, stack_b);
	shift(stack_a);
}
