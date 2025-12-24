/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:34:08 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/24 11:29:22 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft_bonus.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack); // optmize
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

void	rotate_rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
