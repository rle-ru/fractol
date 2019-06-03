/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:38:14 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 17:45:51 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WIDTH 500
# define W_HEIGHT 500
# define MAX_FRACTALS 1
# include <math.h>

typedef double _Complex		t_complex;

typedef enum				e_fractals
{
	man,
	jul
}							t_fractals;

typedef enum				e_bool
{
	false,
	true
}							t_bool;

typedef enum				e_error
{
	ok,
	falloc
}							t_error;

typedef struct				s_img
{
	void					*img_ptr;
	int						*img;
	int						bpp;
	int						stride;
	int						endian;
}							t_img;

typedef struct				s_canvas
{
	void					*mlx_ptr;
	void					*window;
	t_img					img;

}							t_canvas;

typedef struct				s_model
{
	void					(*f)();
}							t_model;

typedef struct				e_fra
{
	t_canvas				canvas;
	t_model					fractal[MAX_FRACTALS];
	t_fractals				curr_fractal;
}							t_fra;

typedef struct				s_man
{
	int						x;
	int						y;
	int						iter;
	t_complex				c;
}							t_man;

/*
**	Allocates memory according to needs, starts the MLX loop.
**	returns ok if everything went good, else a revelant error type.
*/
t_error						init_fractol(t_fra *fra);

/*
**	Inputs management.
*/
int							key_hook(int key, t_fra *fra);

/*
**	The main drawing function. It is called on every mlx_loop.
*/
int							draw(t_fra *fra);

/*
**	Exits the program properly, free any remaining pointer, and printing
**	error messages if needed.
*/
int							leave(t_error error, t_fra *fra);

/*
**	The mandelbrot model.
*/
void						mandelbrot(t_fra *fra);

#endif
