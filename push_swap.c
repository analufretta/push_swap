/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:10 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/02 18:25:45 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static int	push_swap(t_stack_node **a, t_stack_node **b);

int	main(int argc, char *argv[])
{
	char			**split;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2 && !argv[1][0])
		return (write(1, "Error\n", 6));
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (1);
		if (intitialize_stack_a(&a, split) != 0)
			return (free_array(split), write(1, "Error\n", 6));
		free_array(split);
	}
	else if (argc > 2)
	{
		if (intitialize_stack_a(&a, argv + 1) != 0)
			return (write(1, "Error\n", 6));
	}
	return (push_swap(&a, &b));
}

static int	push_swap(t_stack_node **a, t_stack_node **b)
{
	if (is_sorted(*a))
		return (0);
	else if (stack_len(*a) == 2)
		swap_a(a);
	else if (stack_len(*a) == 3)
		tiny_sort(a);
	else
		sort_stack(a, b);
	return (0);
}
