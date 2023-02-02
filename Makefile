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
SRC			=	main.c \
				main_fractol.c \
				complex.c \
				coordinate.c \
				draw_mandelbrot.c \
				main_mandelbrot.c \


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
OBJDIR		= ./obj
INCSDIR   	= ./include

INCS		= -I$(INCSDIR) -I$(LIBFTDIR)/include
# INCS		= -I$(INCSDIR) -I$(LIBFTDIR)/include -I$(MINILIBDIR)/
RMFLAGS		= -r

SRCS   		= $(addprefix $(SRCDIR)/, $(SRC))
OBJS   		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

CC 	   		= cc
CFLAGS 		= -MMD -Wall -Wextra -Werror

.PHONY:	all clean fclean re
all: $(LIBFT) $(NAME)
# all: $(LIBFT) $(MINILIB) $(NAME)
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(RMFLAGS) $(OBJDIR)
# clean:
# 	$(MAKE) clean -C $(LIBFTDIR)
# 	$(MAKE) clean -C $(MINILIBDIR)
#	$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)
re: fclean all


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L/usr/X11R6/lib  -lmlx -lX11 -lXext -framework OpenGL -framework AppKit $(INCS) $(OBJS) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(MINILIB) $(MINILIBOS) $(LIBFT) -lXext -lX11 -lm -lz -o $(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
# $(MINILIB):
#	$(MAKE) -C $(MINILIBDIR)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
