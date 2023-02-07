# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 22:01:03 by shtanemu          #+#    #+#              #
#    Updated: 2023/01/16 22:01:03 by shtanemu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
BNSNAME		=	fractol_bonus

SRC			=	main.c \
				main_fractol.c \
				validate_args.c \
				is_which_set.c \
				complex.c \
				coordinate.c \
				window_management.c \
				pixel_color_gen.c \
				caliculate_zk.c \
				draw_mandelbrot.c \
				draw_julia.c \
				main_mandelbrot.c \
				main_julia.c \

BNSSRC		=	main_bonus.c \
				main_fractol_bonus.c \
				validate_args_bonus.c \
				is_which_set_bonus.c \
				complex_bonus.c \
				coordinate_bonus.c \
				window_management_bonus.c \
				pixel_color_gen_bonus.c \
				caliculate_zk_bonus.c \
				draw_mandelbrot_bonus.c \
				draw_julia_bonus.c \
				draw_burningship_bonus.c \
				main_mandelbrot_bonus.c \
				main_julia_bonus.c \
				main_burningship_bonus.c \


LIBFTNAME	= 	libft
LIBFTDIR 	= 	$(LIBFTNAME)
LIBFT		= 	$(LIBFTDIR)/$(LIBFTNAME).a

# MINILIBNAME =	libmlx
# MINILIBDIR	=	minilibx-linux
# MINILIB		=	$(MINILIBDIR)/$(MINILIBNAME).a
# MINILIB		=	$(MINILIBDIR)/$(MINILIBNAME).a
# MINILIBOS	=	$(MINILIBDIR)/$(MINILIBNAME)_Darwin.a
# MINILIBOS	=	$(MINILIBDIR)/$(MINILIBNAME)_Linux.a

SRCDIR		= ./src
BNSSRCDIR	= ./bnssrc
OBJDIR		= ./obj
BNSOBJDIR	= ./bnsobj
INCSDIR   	= ./include

INCS		= -I$(INCSDIR) -I$(LIBFTDIR)/include
# INCS		= -I$(INCSDIR) -I$(LIBFTDIR)/include -I$(MINILIBDIR)/
RMFLAGS		= -r

SRCS   		= $(addprefix $(SRCDIR)/, $(SRC))
BNSSRCS   	= $(addprefix $(BNSSRCDIR)/, $(BNSSRC))
OBJS   		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
BNSOBJS   	= $(addprefix $(BNSOBJDIR)/, $(notdir $(BNSSRCS:.c=.o)))

CC 	   		= cc
CFLAGS 		= -MMD -Wall -Wextra -Werror -fsanitize=address


.PHONY:	all clean fclean re bonus

all: $(LIBFT) $(NAME)
# all: $(LIBFT) $(MINILIB) $(NAME)

bonus: $(LIBFT) $(BNSNAME)

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(RMFLAGS) $(OBJDIR)
	$(RM) $(RMFLAGS) $(BNSOBJDIR)

# clean:
# 	$(MAKE) clean -C $(LIBFTDIR)
# 	$(MAKE) clean -C $(MINILIBDIR)
#	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)
	$(RM) $(BNSNAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L/usr/X11R6/lib -lmlx -lX11 -lXext -framework OpenGL -framework AppKit $(INCS) $(OBJS) $(LIBFT) -o $(NAME)

$(BNSNAME): $(BNSOBJS)
	$(CC) $(CFLAGS)  -L/usr/X11R6/lib -lmlx -lX11 -lXext -framework OpenGL -framework AppKit $(INCS) $(BNSOBJS) $(LIBFT) -o $(BNSNAME)

#	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(MINILIB) $(MINILIBOS) $(LIBFT) -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
# $(MINILIB):
#	$(MAKE) -C $(MINILIBDIR)

$(OBJDIR):
	@mkdir -p $@

$(BNSOBJDIR):
	@mkdir -p $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

$(BNSOBJDIR)/%.o: $(BNSSRCDIR)/%.c | $(BNSOBJDIR)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
