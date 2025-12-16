/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:32:38 by afretta-          #+#    #+#             */
/*   Updated: 2025/10/28 17:31:23 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = 0;
	while (dstlen < dstsize - 1 && src[dstlen])
	{
		dst[dstlen] = src[dstlen];
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (srclen);
}
