/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:16:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 11:31:04 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <pthread.h>

int			draw(t_fra *fra)
{
	t_pthread	threads[MAX_THREADS];
	t_fra		cpy[MAX_THREADS];
	int			i;

	ft_bzero(fra->canvas.img.img, sizeof(int) * W_WIDTH * W_HEIGHT);
	i = 0;
	while (i < MAX_THREADS)
	{
		ft_memcpy(&cpy[i], fra, sizeof(t_fra));
		cpy[i].data.miny = i * W_HEIGHT / MAX_THREADS;
		cpy[i].data.maxy = (i + 1) * W_HEIGHT / MAX_THREADS;
		pthread_create(&threads[i], NULL, (fra->fractal[fra->curr_fractal].f), &cpy[i]);
		++i;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fra->canvas.mlx_ptr, fra->canvas.window,
		fra->canvas.img.img_ptr, 0, 0);
	return (0);
}
