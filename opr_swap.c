/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:26:53 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/22 16:10:24 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elements(t_stack_node **stack)//WRONG! THINK ABOUT PREVIOUS NODES
{
	t_stack_node *first;
	t_stack_node *second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	else
		first = (*stack)->next;
		second = *stack;
		*stack = first;
		(*stack)->next = second;


}

int	swap_a(t_stack_node **stack_a)
{
	swap_elements(stack_a);
	return(write(1, "sa\n", 3));
}

int	swap_b(t_stack_node **stack_b)
{
	swap_elements(stack_b);
	return(write(1, "sb\n", 3));
}

int	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_elements(stack_a);
	swap_elements(stack_b);
	return(write(1, "sb\n", 3));
}
