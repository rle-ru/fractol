/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:40:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/18 17:41:25 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "math.h"
#include "complex.h"

int		mouse_unhook(int key, int x, int y, t_fra *fra)
{
	(void)x;
	(void)y;
	fra->mkeys[key] = false;
	return (0);
}

int		mouse_notify(int x, int y, t_fra *fra)
{
	fra->mx = x;
	fra->my = y;
	return (0);
}

int		mouse_hook(int key, int x, int y, t_fra *fra)
{
	fra->mkeys[key] = true;
	if (key == M_SCROLL_UP)
	{
		fra->data.x1 = (x + fra->data.x1) * 0.9 - W_WIDTH * 0.5;
		fra->data.y1 = (y + fra->data.y1) * 0.9 - W_HEIGHT * 0.5;
		fra->data.zoom *= 0.9;
	}
	else if (key == M_SCROLL_DOWN)
	{
		fra->data.zoom *= 1.1;
		fra->data.x1 = x - (x - fra->data.x1) * 1.1;
		fra->data.y1 = y - (y - fra->data.y1) * 1.1;
	}
	return (0);
}
