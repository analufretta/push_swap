/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:42:14 by afretta-          #+#    #+#             */
/*   Updated: 2025/10/14 17:20:57 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest_value;
	const unsigned char	*src_value;

	dest_value = dst;
	src_value = src;
	while (n > 0)
	{
		*dest_value = *src_value;
		dest_value++;
		src_value++;
		n--;
	}
	return (dst);
}
