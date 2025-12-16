/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:49:10 by afretta-          #+#    #+#             */
/*   Updated: 2025/10/28 13:18:36 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_len(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	write_number(char *str, int n, size_t len)
{
	if (n == INT_MIN)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		n = -n;
		*str = '-';
	}
	else if (n == 0)
		str[--len] = '0';
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = find_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	write_number(str, n, len);
	return (str);
}
