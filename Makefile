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

LIBFTNAME	= 	libft
LIBFTDIR 	= 	$(LIBFTNAME)
LIBFT		= 	$(LIBFTDIR)/$(LIBFTNAME).a

SRCDIR		= ./src
OBJDIR		= ./obj
INCSDIR   	= ./include

INCS		= -I$(INCSDIR) -I$(LIBFTDIR)/include
RMFLAGS		= -r

SRCS   		= $(addprefix $(SRCDIR)/, $(SRC))
OBJS   		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

CC 	   		= cc
CFLAGS 		= -MMD -Wall -Wextra -Werror
RM			= rm


.PHONY:	all clean fclean re
all: $(LIBFT) $(NAME)
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

$(NAME): $(OBJS)
	$(CC) $(INCS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
