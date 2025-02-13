/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:06:55 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/10 11:53:28 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double					get_gradient(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

int						apply_gradient(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int						get_color(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = apply_gradient((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = apply_gradient((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = apply_gradient(c1 & 0xFF, c2 & 0xFF, p);
	return ((unsigned char)r << 16 | (unsigned char)g << 8 | (unsigned char)b);
}
