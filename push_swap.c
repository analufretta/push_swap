/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:10 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/31 11:42:28 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <stdio.h>

static int	push_swap(t_stack_node **a);

int	main(int argc, char *argv[])
{
	char **split;
	t_stack_node *a;
	// t_stack_node *b;
	a = NULL;
	// b = NULL;

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
	return (push_swap(&a));
}
static int	push_swap(t_stack_node **a)
{
	if (is_sorted(*a) == 0)
		return (0);
	else if (stack_len(*a) == 2)
		swap_a(a);
	else if (stack_len(*a) == 3)
		tiny_sort(a);
	while(*a)
	{
		printf("a: %d\n", (*a)->value);
		(*a) = (*a)->next;
	}
	// else if
	// 	return (sort_stack(a, b), 0); //todo:algorithm
	return (0);
}
