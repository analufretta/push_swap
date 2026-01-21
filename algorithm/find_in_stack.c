/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:31:37 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 09:28:38 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	int				highest;

	if (!stack)
		return (NULL);
	highest = stack->value;
	highest_node = stack;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*find_lowest(t_stack_node *stack)
{
	t_stack_node	*lowest_node;
	int				lowest;

	if (!stack)
		return (NULL);
	lowest = stack->value;
	lowest_node = stack;
	while (stack)
	{
		if (stack->value < lowest)
		{
			lowest = stack->value;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node);
}

t_stack_node	*find_highest_rank(t_stack_node *stack)
{
	t_stack_node	*highest_rank;
	int				highest;

	if (!stack)
		return (NULL);
	highest = stack->rank;
	highest_rank = stack;
	while (stack)
	{
		if (stack->allowed)
		{
			if (stack->rank > highest)
			{
				highest = stack->rank;
				highest_rank = stack;
			}
		}
		stack = stack->next;
	}
	return (highest_rank);
}

t_stack_node	*find_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;

	cheapest_node = NULL;
	while (stack)
	{
		if (!stack->cheapest)
			stack = stack->next;
		else
			break ;
	}
	cheapest_node = stack;
	return (cheapest_node);
}
