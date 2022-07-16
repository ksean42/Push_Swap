/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 03:39:27 by ksean             #+#    #+#             */
/*   Updated: 2020/08/02 05:10:07 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack **stack)
{
	t_stack	*curr;
	int		i;

	i = 1;
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	while (curr)
	{
		curr->index = i;
		i++;
		curr = curr->prev;
	}
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_free(t_stack *stack)
{
	t_stack *next;

	if (stack)
	{
		while (stack)
		{
			next = stack->next;
			free(stack);
			stack = next;
		}
	}
}

int		is_sorted(t_stack **stack)
{
	t_stack *curr;

	curr = *stack;
	if (!curr)
		return (0);
	while (curr)
	{
		if (curr->next && curr->value >= curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

t_stack	*get_min(t_stack **stack)
{
	t_stack *curr;
	t_stack *min;

	curr = *stack;
	min = curr;
	while (curr)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}
