/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:38:14 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/07 17:07:46 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WIDTH 500
# define W_HEIGHT 500
# define MAX_FRACTALS 3
# define MAX_COLORS 3
# define MAX_THREADS 16
# include <math.h>
# include <pthread.h>

typedef double _Complex		t_complex;
typedef pthread_t			t_pthread;

typedef enum				e_fractals
{
	man,
	jul,
	ship
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

typedef struct				s_cmodel
{
	int						(*f)();
}							t_cmodel;

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
	int						x1;
	int						y1;
	int						iter;
	int						max_iter;
	t_complex				c;
	int						miny;
	int						maxy;
	double					zoom;
	double					julia;
}							t_data;

typedef struct				e_fra
{
	t_canvas				canvas;
	t_model					fractal[MAX_FRACTALS];
	int						curr_fractal;
	t_cmodel				colors[MAX_COLORS];
	int						curr_color;
	t_data					data;
	t_bool					keys[300];
	t_bool					mkeys[10];
	int						mx;
	int						my;
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
**	Keyboards inputs managment.
*/
int							key_unhook(int key, t_fra *fra);

/*
**	Mouse inputs managment.
*/
int							mouse_hook(int key, int x, int y, t_fra *fra);

/*
**	Mouse inputs managment.
*/
int							mouse_unhook(int key, int x, int y, t_fra *fra);

/*
**	Mouse inputs managment.
*/
int							mouse_notify(int x, int y, t_fra *fra);

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
**	The mandelbrot set.
*/
void						*mandelbrot(t_fra *fra);

/*
**	The Julia set.
*/
void						*julia(t_fra *fra);

/*
**	The burning ship set.
*/
void						*burning_ship(t_fra *fra);

/*
**	Puts a pixel into the mlx image.
*/
void						put_pixel(int *img, t_data *data, int color);

/*
**	Simple color set, black and white.
*/
int							set_0(t_data *data);

int							set_1(t_data *data);

int							set_2(void);
#endif
