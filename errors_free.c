/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:10:38 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/18 17:02:52 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_and_free(t_stack_node **stack)
{
	t_stack_node *tmp;

	if (!stack || !*stack)
		return (1);

	while (*stack)
    {
		tmp = (*stack)->next; 
		free(*stack);
		*stack = tmp;
    }
	*stack = NULL;
	return (1);
}

int	repeated(int nb, t_stack_node *stack)
{
	while(stack)
	{
		if (nb == stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
