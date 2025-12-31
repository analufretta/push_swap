/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:45:46 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/31 10:46:32 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <stdio.h>

long	ps_atol(const char *str, unsigned int *error)
{
	long	nb;
	size_t	i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (sign == 1 && (nb > (LONG_MAX - (str[i] - '0')) / 10))
			return (*error = 1, 0);
		if (sign == -1 && (-nb < (LONG_MIN + (str[i] - '0')) / 10))
			return (*error = 1, 0);
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

t_stack_node *find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while(stack->next)
		stack = stack->next;
	return(stack);
}

size_t	stack_len(t_stack_node *stack)
{
	size_t	len;

	len = 0;
	if (!stack)
		return (0);
	while(stack)
	{
		stack = stack->next;
		len++;
	}
	return(len);
}
int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while(stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		else
		stack = stack->next;
	}
	return (0);
}
