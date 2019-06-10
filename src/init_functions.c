/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:03:11 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/07 20:29:53 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void		init_functions(t_fra *fra)
{
	fra->fractal[0].f = &mandelbrot;
	fra->fractal[0].index = man;
	ft_strcpy(fra->fractal[0].name, "mandelbrot");
	fra->fractal[1].f = &julia;
	fra->fractal[1].index = jul;
	ft_strcpy(fra->fractal[1].name, "julia");
	fra->fractal[2].f = &burning_ship;
	fra->fractal[2].index = ship;
	ft_strcpy(fra->fractal[2].name, "burning ship");
	fra->fractal[3].f = &sierpinski;
	fra->fractal[3].index = sier;
	ft_strcpy(fra->fractal[3].name, "sierpinski's carpet");
	fra->colors[0].f = &set_0;
	fra->colors[1].f = &set_1;
	fra->colors[2].f = &set_2;
}
