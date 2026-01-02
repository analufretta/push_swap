/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:07:39 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/02 18:29:57 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static bool	requisits_stack(char *value, t_stack_node **stack);
static int	append_to_stack(int nb, t_stack_node **stack);

int	intitialize_stack_a(t_stack_node **stack, char **argv)
{
	size_t	i;
	size_t	j;
	char	**array;

	i = 0;
	while (argv[i])
	{
		if (!argv[i][0])
			return (error_and_free(stack), 1);
		array = ft_split(argv[i], ' ');
		if (!array || !array[0])
			return (free_array(array), error_and_free(stack), 1);
		j = 0;
		while (array[j])
		{
			if (!requisits_stack(array[j++], stack))
				return (free_array(array), 1);
		}
		free_array(array);
		i++;
	}
	return (0);
}

static bool	requisits_stack(char *value, t_stack_node **stack)
{
	long			nb;
	size_t			i;
	unsigned int	error;

	i = 0;
	if (value[0] == '+' || value[0] == '-')
		i++;
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (error_and_free(stack), false);
		i++;
	}
	error = 0;
	nb = ps_atol(value, &error);
	if (nb > INT_MAX || nb < INT_MIN || error == 1)
		return (error_and_free(stack), false);
	if (!is_repeated(nb, *stack))
	{
		if (append_to_stack(nb, stack) != 0)
			return (false);
	}
	else
		return (error_and_free(stack), false);
	return (true);
}

static int	append_to_stack(int nb, t_stack_node **stack)
{
	t_stack_node	*new;
	t_stack_node	*last;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (error_and_free(stack), 1);
	new->value = nb;
	new->index = -1;
	new->cost = 0;
	new->target_node = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (!*stack)
	{
		*stack = new;
		return (0);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (0);
}
