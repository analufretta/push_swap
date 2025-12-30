/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:34:08 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/30 15:37:56 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	rotate_a(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
