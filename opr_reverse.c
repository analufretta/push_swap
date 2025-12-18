/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:33:57 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/18 18:43:05 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	reverse_rotate()
{
	last stack = top
	bottom -1->next = NULL;
}

int	rotate_a()
{
	reverse_rotate(a);
	return(write(1, "rra\n", 4));
}

int	rotate_b()
{
	reverse_rotate(b);
	return(write(1, "rrb\n", 4));
}

int	rotate_rr()
{
	reverse_rotate(a);
	reverse_rotate(b);
	return(write(1, "r4r\n", 4));
}