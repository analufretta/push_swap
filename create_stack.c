/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:07:39 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/17 16:27:01 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	requisits_stack(char *array, t_stack_node **stack_ptr);

void	intitialize_stack_a(t_stack_node **stack, char **argv)
{
	int i;
	int j;
	char **array;

	i = 0;
	while (argv[i])
	{
		if (!argv[i][0])
			error_and_free(stack);//TODO: free, write Error and exut
		array = ft_split(argv[i], ' ');
		if (!array || !array[0])
			error_and_free(stack);//TODO: free, write error and exit
		j = 0;
		while (array[j])
			requisits_stack(array[j], stack);//TODO
			j++;
		}
		free_array(array);//TODO
		i++;
}

void	requisits_stack(char *array, t_stack_node **stack)
{
	long	nb;
	int		i;

	i = 0;
	if (array[0] == '+' || array[0] == '-')
		i++;
	while (array[i])
	{
		if (ft_isdigit(array[i]))
			i++;
		else
			break ; //TODO:erro ip break;
	}
	nb = ps_atol(array);
	if (nb > INT_MAX || nb < INT_MIN)
		//TODO: error
	if (!repeated(nb, stack))// TODO: function to check for repeated nb
		append_to_stack(nb, stack); //TODO: function to add nb to linked list
	else
		//TODO: errror
}
