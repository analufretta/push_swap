/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:10 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/23 11:08:58 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (write(2, "Error\n", 6));
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (1);
		if (intitialize_stack_a(&a, split) != 0)
			return (free_array(split), write(2, "Error\n", 6));
		free_array(split);
	}
	else if (argc > 2)
	{
		if (intitialize_stack_a(&a, argv + 1) != 0)
			return (write(2, "Error\n", 6));
	}
	return (push_swap(&a, &b));
}

static int	push_swap(t_stack_node **a, t_stack_node **b)
{
	size_t	len_a;

	if (is_sorted(*a))
		return (error_and_free(a), 0);
	len_a = stack_len(*a);
	if (len_a == 2)
		swap_a(a);
	else if (len_a == 3)
		sort_three(a);
	else if (len_a == 4 || len_a == 5)
		sort_until_five(a, b);
	else
		sort_stack(a, b);
	error_and_free(a);
	return (0);
}
