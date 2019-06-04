/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:38:14 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 13:10:51 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WIDTH 500
# define W_HEIGHT 500
# define MAX_FRACTALS 1
# define MAX_THREADS 4
# include <math.h>
# include <pthread.h>

typedef double _Complex		t_complex;
typedef pthread_t			t_pthread;

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
	falloc,
	usage
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
	void					*(*f)();
	t_fractals				index;
	char					name[15];
}							t_model;

typedef struct				s_data
{
	int						x;
	int						y;
	int						iter;
	t_complex				c;
	int						miny;
	int						maxy;
	double					zoom;
}							t_data;

typedef struct				e_fra
{
	t_canvas				canvas;
	t_model					fractal[MAX_FRACTALS];
	t_fractals				curr_fractal;
	t_data					data;
}							t_fra;

/*
**	Allocates memory according to needs, starts the MLX loop.
**	returns ok if everything went good, else a revelant error type.
*/
t_error						init_fractol(t_fra *fra);

/*
**	Fill the function pointers array.
*/
void						init_functions(t_fra *fra);

/*
**	Parse arguments to select starting fractal, or print usage.
*/
t_error						parse_arguments(t_fra *fra, int ac, char **av);

/*
**	Keyboard inputs managment.
*/
int							key_hook(int key, t_fra *fra);

/*
**	Mouse inputs managment.
*/
int							mouse_hook(int key, int x, int y, t_fra *fra);

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
void						*mandelbrot(t_fra *fra);

/*
**	Puts a pixel into the mlx image.
*/
void						put_pixel(int *img, t_data *data, int color);

#endif
