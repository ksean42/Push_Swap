/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 03:44:21 by ksean             #+#    #+#             */
/*   Updated: 2020/08/15 18:07:16 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift(t_stack **stack)
{
	t_stack	*min;
	t_stack	*head;
	int		max;
	int		half;
	int		ind;

	head = *stack;
	min = get_min(stack);
	max = head->index;
	half = head->index / 2;
	ind = min->index;
	if (ind > half)
		while (ind++ != max)
			rx(stack, "ra");
	else
		while (ind-- != 0)
			rrx(stack, "rra");
}

void	shift_stacks(t_stack **stack_a, t_stack **stack_b,
		int ra_count, int rb_count)
{
	if (rb_count > 0)
		while (rb_count-- != 0)
			rx(stack_b, "rb");
	else if (rb_count < 0)
		while (rb_count++ != 0)
			rrx(stack_b, "rrb");
	if (ra_count > 0)
		while (ra_count-- != 0)
			rx(stack_a, "ra");
	else if (ra_count < 0)
		while (ra_count++ != 0)
			rrx(stack_a, "rra");
}

int		count_ops(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	int	count;
	int	size_a;

	size_a = stack_a->index;
	count = 1 + (size_b - stack_b->index) >= stack_b->index ?
	stack_b->index : size_b - stack_b->index + 1;
	stack_a = find_elem_to_ins(stack_a, stack_b);
	count += (stack_a->index >= (size_a / 2)) ?
	(size_a - stack_a->index + 1) : (stack_a->index - 1);
	return (count);
}

t_stack	*find_elem_to_ins(t_stack *a_elem, t_stack *b_elem)
{
	t_stack	*min;
	int		found;

	found = 0;
	min = get_min(&a_elem);
	while (a_elem->next)
	{
		if (a_elem->next && a_elem->value < b_elem->value
		&& a_elem->next->value > b_elem->value)
		{
			found = 1;
			break ;
		}
		a_elem = a_elem->next;
	}
	if (!found && min->prev &&
	(b_elem->value > min->prev->value || b_elem->value < min->value))
		a_elem = min->prev;
	return (a_elem);
}
