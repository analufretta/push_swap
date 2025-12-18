/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:10 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/18 12:25:57 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char **split;
	t_stack_node *a;
	// // t_stack_node *b;
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
		intitialize_stack_a(&a, split);
		free_array(split); // TODO;
	}
	else if (argc > 2)
		intitialize_stack_a(&a, argv + 1);
	// if (!sorted_stack(a))
	// {
	// 	//TODO ALGORITHM: this is where stack b enters
	// }
	// free_stack(&a);
	// return (0);
}