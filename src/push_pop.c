/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 03:35:57 by ksean             #+#    #+#             */
/*   Updated: 2020/08/02 23:41:00 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, int value)
{
	t_stack *new_node;
	t_stack *curr;

	curr = *stack;
	if (!(new_node = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return ;
	new_node->value = value;
	if (curr)
	{
		curr->prev = new_node;
		new_node->next = curr;
	}
	*stack = new_node;
	indexing(stack);
}

void	pop(t_stack **stack)
{
	t_stack *curr;
	t_stack *second;

	curr = *stack;
	if (!curr)
		return ;
	second = curr->next;
	if (second)
		second->prev = NULL;
	free(curr);
	curr = NULL;
	*stack = second;
}
