/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:40:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/21 12:54:33 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "math.h"

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
		x = 0;
		y = 0;
		fra->data.zoom *= 0.9;
	}
	else if (key == M_SCROLL_DOWN)
		fra->data.zoom *= 1.1;
	return (0);
}
