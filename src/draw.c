/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:16:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 07:34:24 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"

int			draw(t_fra *fra)
{
	ft_bzero(fra->canvas.img.img, sizeof(int) * W_WIDTH * W_HEIGHT);
	mlx_put_image_to_window(fra->canvas.mlx_ptr, fra->canvas.window,
		fra->canvas.img.img_ptr, 0, 0);
	return (0);
}
