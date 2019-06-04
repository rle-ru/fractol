/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:03:11 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 09:08:03 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void		init_functions(t_fra *fra)
{
	fra->fractal[0].f = &mandelbrot;
	fra->fractal[0].index = man;
	ft_strcpy(fra->fractal[0].name, "mandelbrot");
}
