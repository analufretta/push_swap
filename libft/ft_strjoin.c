/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:55:43 by afretta-          #+#    #+#             */
/*   Updated: 2025/10/20 10:51:40 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dst = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	ft_strlcat(dst, s1, s1len + 1);
	ft_strlcat(dst, s2, (s1len + s2len + 1));
	return (dst);
}
