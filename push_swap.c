/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:10 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/30 16:44:25 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char **split;
	t_stack_node *a;
	t_stack_node *b;
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
	{	if (intitialize_stack_a(&a, argv + 1) != 0)
			return (write(1, "Error\n", 6));
	}
	return (push_swap(&a, &b));
}
int	push_swap(t_stack_node **a, t_stack_node **b)
{
	if (is_sorted(a) == 0)
		return (0);
	else if (stack_len(*a) == 2)
		return (swap_a(a), 0);
	else if (stack_len(*a) == 3)
		return (tiny_sort(a), 0); //todo
	else
		return (sort_stack(a, b), 0); //todo:algorithm
}
