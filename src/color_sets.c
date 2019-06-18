/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:53:30 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/18 17:42:34 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/types.h>
#include <math.h>

int		set_4(t_data *data)
{
	double		t;

	if (data->discob)
		t = ((double)data->iter / (double)data->max_iter) * data->sdisco;
	else
		t = ((double)data->iter / (double)data->max_iter);
	return (0xF0FFF0 / (t + 1));
}

int		set_3(t_data *data)
{
	double		t;

	t = ((double)data->iter / (double)data->max_iter);
	if (data->discob)
		return ((((u_int8_t)(9 * (1 - t) * t * t * t * 255
						* data->sdisco10 + 20) << 16) & 0xFF0000)
			| (((u_int8_t)(15 * (1 - t) * (1 - t) * t * t * 255
						* data->sdisco5 + 20) << 8) & 0xFF00)
			| (((u_int8_t)(8.5 * (1 - t) * (1 - t) * (1 - t)
						* t * 255 * data->sdisco2 + 20) & 0xFF)));
	else
		return ((((u_int8_t)(9 * (1 - t) * t * t * t * 255) << 16) & 0xFF0000)
			| (((u_int8_t)(15 * (1 - t) * (1 - t) * t * t * 255) << 8) & 0xFF00)
			| (((u_int8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)
					& 0xFF)));
}

int		set_2(void)
{
	return (0xFFFFFF);
}

int		set_1(t_data *data)
{
	double		a;

	a = get_gradient(data->iter, 3, data->max_iter);
	return (get_color(0xFFFFFF, 0x0000FF, a));
}

int		set_0(t_data *data)
{
	double	a;

	a = 255 * data->iter / data->max_iter;
	return ((unsigned char)a << 16 | (unsigned char)a << 8 | (unsigned char)a);
}
