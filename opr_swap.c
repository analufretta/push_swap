/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:26:53 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/23 17:36:50 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elements(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;

	first = (*stack);
	second = first->next;
	first->next = second->next;
	if(second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	swap_a(t_stack_node **stack_a)
{
	swap_elements(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack_node **stack_b)
{
	swap_elements(stack_b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_elements(stack_a);
	swap_elements(stack_b);
	write(1, "sb\n", 3);
}
