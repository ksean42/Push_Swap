/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:42:21 by ksean             #+#    #+#             */
/*   Updated: 2020/08/10 23:00:45 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include "libft.h"

typedef struct		s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					validation(t_stack **stack, char **argv, int argc);
int					is_valid(char *value);
void				indexing(t_stack **stack);
void				free_arr(char **arr);
int					is_sorted(t_stack **stack);
void				ft_free(t_stack *stack);
int					check_dups(t_stack *stack);

void				push(t_stack	**stack, int value);
void				pop(t_stack	**stack);
void				px(t_stack **stack_dest, t_stack **stack_src, char *op);
void				sx(t_stack **stack, char *op);
void				ss(t_stack **stack_a, t_stack **stack_b, int v);
void				rx(t_stack **stack, char *op);
void				rr(t_stack **stack_a, t_stack **stack_b, int v);
void				rrx(t_stack **stack, char *op);
void				rrr(t_stack **stack_a, t_stack **stack_b, int v);
void				rrx_both(t_stack **stack_a, t_stack **stack_b,
					int *ra_count, int *rb_count);
void				rx_both(t_stack **stack_a, t_stack **stack_b,
					int *ra_count, int *rb_count);

t_stack				*get_min(t_stack **stack);
void				solve(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack);
void				move_to_b(t_stack **stack_a, t_stack **stack_b);
void				insert(t_stack **stack_a, t_stack **stack);
int					count_ops(t_stack *stack_a, t_stack *stack_b, int size_b);
t_stack				*find_elem_to_ins(t_stack *a_elem, t_stack *b_elem);
void				put_elem(t_stack **stack_a, t_stack **stack_b,
					int id, int size_b);
void				shift(t_stack **stack);
void				shift_stacks(t_stack **stack_a, t_stack **stack_b,
					int ra_count, int rb_count);

#endif
