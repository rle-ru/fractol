/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:53:30 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/10 11:54:21 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
