/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:41:25 by afretta-          #+#    #+#             */
/*   Updated: 2025/10/28 18:02:53 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (slen > 0)
	{
		if (s[slen] == (char)c)
			return ((char *)s + (slen));
		else
			slen--;
	}
	if (s[slen] == (char)c)
		return ((char *)s + (slen));
	return (NULL);
}
