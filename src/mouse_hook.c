/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:40:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 13:11:39 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int		mouse_hook(int key, int x, int y, t_fra *fra)
{
	if (key == M_SCROLL_UP)
		fra->data.zoom *= 0.9;
	else if (key == M_SCROLL_DOWN)
		fra->data.zoom *= 1.1;
	(void)x;//
	(void)y;//
	return (0);
}
