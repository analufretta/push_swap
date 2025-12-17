/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:08:15 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/17 10:14:19 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef unsigned long long UNIT64;
typedef struct Point
{
	double x, y;
} Point;

int	main(void)
{
	UNIT64 example = 14;
	Point p;
	p.x = 0.24;
	p.y = 0.28;

	printf("%llu\n", example);
	printf("%f\n%f\n", p.x, p.y);
	return (0);
}
