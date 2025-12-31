/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:31:37 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/31 11:39:10 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack_node *find_highest(t_stack_node *stack)
{
	t_stack_node *highest_node;
	int	highest;

	highest = INT_MIN;
	if (!stack)
		return (NULL);
	while(stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return(highest_node);
}
