/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:40:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 14:55:44 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "math.h"

int		mouse_hook(int key, int x, int y, t_fra *fra)
{
	if (key == M_SCROLL_UP)
	{
		fra->data.x1 = round(((double)(((double)W_WIDTH / 2.0) + fra->data.x1) - (double)x) * 0.9);
		fra->data.y1 = round(((double)(((double)W_HEIGHT / 2.0) + fra->data.y1) - (double)y) * 0.9);
		// fra->data.x1 = (x / fra->data.zoom + fra->data.x1) - (x / fra->data.zoom * 0.9);
		// fra->data.y1 = (x / fra->data.zoom + fra->data.y1) - (y / fra->data.zoom * 0.9);
		fra->data.zoom *= 0.9;
	}
	else if (key == M_SCROLL_DOWN)
	{
		fra->data.x1 = round(((double)(((double)W_WIDTH / 2.0) + fra->data.x1) - (double)x) * 1.1);
		fra->data.y1 = round(((double)(((double)W_HEIGHT / 2.0) + fra->data.y1) - (double)y) * 1.1);
		// fra->data.x1 += (x / fra->data.zoom + fra->data.x1) - (y / fra->data.zoom * 1.1);
		// fra->data.y1 += (y / fra->data.zoom + fra->data.y1) - (y / fra->data.zoom * 1.1);
		fra->data.zoom *= 1.1;
	}
	(void)x;//
	(void)y;//
	return (0);
}
