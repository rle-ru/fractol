# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 14:17:52 by rle-ru            #+#    #+#              #
#    Updated: 2019/06/21 12:48:59 by rle-ru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fractol

# Raw Sources

SRCS_RAW			:=	\
						main.c								\
						init_functions.c					\
						parse_arguments.c					\
						init_fractol.c						\
						key_hook.c							\
						draw.c								\
						leave.c								\
						put_pixel.c							\
						mandelbrot.c						\
						julia.c								\
						burningship.c						\
						sierpinski.c						\
						leif.c								\
						feigen.c							\
						mouse_hook.c						\
						colors.c							\
						color_sets.c						\

# Directories

SRCSDIR   			=	src

OBJSDIR   			=	obj

LIBSPATH			=	.

LIBS				:=	$(LIBSPATH)/libft					\

INCDIR				:=	$(LIBS:%=%/includes) 				\
						/usr/local/include					\
						includes							\
						minilibx

# Files

SRCS				:=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		:=	$(OBJS:%.o=%.d)

LIBFILES			:=	$(foreach LIB, $(LIBS), $(LIB)/$(notdir $(LIB)).a)

# Compiler Config

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra -flto -Ofast

INCLUDES			:=	$(addprefix -I ,$(INCDIR))	

INCLIBS				:=	$(foreach LIB,$(LIBS),-L $(LIB) $(subst lib,-l,$(notdir $(LIB))))

# Main Target

all					:	libs $(NAME)

$(NAME)				: 	$(OBJS) $(LIBFILES)
						$(CC) -o $@ $(CFLAGS) $(INCLIBS) $(OBJS) -framework OpenGL -framework AppKit -L /usr/local/lib -lmlx

# Make Libs

.PHONY				:	libs
libs				:
						@$(foreach LIB, $(LIBS), make -j4 -C $(LIB);)

# Objs Target

-include $(DEPENDENCIES)

$(OBJS)				: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
						@mkdir -p $(OBJSDIR)
						$(CC) -o $@ $(CFLAGS) $(INCLUDES) -MMD -c $<

# Cleanup

.PHONY				:	clean
clean				:
						@$(foreach LIB, $(LIBS), $(MAKE) clean -C $(LIB);)
						rm -rf $(OBJSDIR)

.PHONY				:	fclean
fclean				:	clean
						@$(foreach LIB, $(LIBS), $(MAKE) fclean -C $(LIB);)
						rm -f $(NAME)

.PHONY				:	re
re					:	fclean all

mlx					:	$(OBJS) libs
						make -C minilibx
						$(CC) -o $(NAME) $(CFLAGS) $(INCLIBS) -I minilibx/ $(OBJS) minilibx/libmlx.a -framework OpenGL -framework Appkit -L ./minilibx


