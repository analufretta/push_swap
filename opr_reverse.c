/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:33:57 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/24 11:33:05 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft_bonus.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node *last;
	t_stack_node *bf_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack); // optmize later
	bf_last = last->prev;
	last->prev = NULL;
	bf_last->next = NULL;
	(*stack)->prev = last;
	last->next = (*stack);
	*stack = last;
}

void	rev_rotate_a(t_stack_node **a)
{
	rotate(a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack_node **b)
{
	rotate(b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rrr\n", 4);
}
