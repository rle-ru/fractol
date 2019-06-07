/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:40:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/07 11:59:18 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "math.h"

#include <complex.h>//
int		mouse_hook(int key, int x, int y, t_fra *fra)
{
	if (key == M_SCROLL_UP)
	{
		fra->data.x1 = round(((double)x + (double)fra->data.x1) - ((double)x + (double)fra->data.x1) * 0.9);
		fra->data.y1 = round(((double)y + (double)fra->data.y1) - ((double)y + (double)fra->data.y1) * 0.9);
		fra->data.zoom *= 0.9;
		// fra->data.zoom *= 0.9;
	}
	else if (key == M_SCROLL_DOWN)
	{
		// fra->data.x1 = round(((double)(((double)W_WIDTH * 0.5) + fra->data.x1) - (double)x) * fra->data.zoom);
		// fra->data.y1 = round(((double)(((double)W_HEIGHT * 0.5) + fra->data.y1) - (double)y) * fra->data.zoom);
		// fra->data.zoom *= 1.1;

		fra->data.x1 = round((x + fra->data.x1) * 1.1);
		fra->data.y1 = round((y + fra->data.y1) * 1.1);

		fra->data.zoom *= 1.1;
	}
	if (key == M_LEFT)
		fra->data.julia = ((double)x * -0.002205) + (I * (double)y * 0.00081);
	return (0);
}
