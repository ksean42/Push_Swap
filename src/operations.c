/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 05:50:32 by ksean             #+#    #+#             */
/*   Updated: 2020/08/10 22:42:33 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack **stack_dest, t_stack **stack_src, char *op)
{
	t_stack	*dest;
	t_stack	*src;

	dest = *stack_dest;
	src = *stack_src;
	if (!src)
		return ;
	push(stack_dest, src->value);
	pop(stack_src);
	if (op)
		ft_putendl(op);
}

void	sx(t_stack **stack, char *op)
{
	t_stack	*curr;
	t_stack	*first;
	t_stack	*second;

	curr = *stack;
	if (!curr || !curr->next)
		return ;
	second = curr->next;
	first = second;
	first->prev = NULL;
	second = curr;
	second->next = first->next;
	second->prev = first;
	first->next = second;
	if (second->next)
		second->next->prev = second;
	*stack = first;
	indexing(stack);
	if (op)
		ft_putendl(op);
}

void	rx(t_stack **stack, char *op)
{
	t_stack	*curr;
	t_stack	*tail;
	t_stack	*new_head;

	curr = *stack;
	tail = *stack;
	if (!curr || !curr->next)
		return ;
	new_head = curr->next;
	while (tail->next)
		tail = tail->next;
	curr->prev = tail;
	curr->next = NULL;
	tail->next = curr;
	new_head->prev = NULL;
	*stack = new_head;
	indexing(stack);
	if (op)
		ft_putendl(op);
}

void	rrx(t_stack **stack, char *op)
{
	t_stack *curr;
	t_stack *tail;

	curr = *stack;
	tail = *stack;
	if (!curr || !curr->next)
		return ;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = curr;
	curr->prev = tail;
	*stack = tail;
	indexing(stack);
	if (op)
		ft_putendl(op);
}
