/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:07:39 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/18 12:26:42 by afretta-         ###   ########.fr       */
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
			error_and_free(stack);//TODO
		array = ft_split(argv[i], ' ');
		if (!array || !array[0])
			error_and_free(stack);//TODO
		j = 0;
		while (array[j])
		{
			requisits_stack(array[j], stack);//TODO
			j++;
		}
		free_array(array);//TODO
		i++;
	}
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
		if (!ft_isdigit(array[i]))
			error_and_free(stack);// TODO
		i++
	}
	nb = ps_atol(array);
	if (nb > INT_MAX || nb < INT_MIN)
		error_and_free(stack); //TODO
	if (!repeated(nb, stack))// TODO
		append_to_stack(nb, stack); //TODO
	else;
		error_and_free(stack); //TODO
}

void	append_to_stack(int nb, t_stack_node **stack)
{
	t_stack_node *new;
	t_stack_node *last;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		error_and_free(stack);

	new->value = nb;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;

	if (!*stack)
	{
		*stack = new;
		return;
	}

	last = *stack;
	while (last->next)
		last = last->next;

	last->next = new;
	new->prev = last;
}
