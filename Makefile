# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 01:18:20 by ttakami           #+#    #+#              #
#    Updated: 2022/10/28 20:13:11 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS		= ft_printf.c ft_printf_utils.c ft_uitoa_base.c ft_put_char.c
#SRCSB		=
OBJDIR		= obj
LIBFT		= libft/libft.a
HEADERPATH	= -I include
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#OBJSB		= $(addprefix $(OBJDIR)/, $(SRCSB:.c=.o))

#ifdef WITH_BONUS
#ALL_OBJS	= $(OBJSB)
#else
ALL_OBJS	= $(OBJS)
#endif

all:	directories $(NAME)

directories:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	@make -C libft clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re:	fclean all

#bonus:
#	@$(MAKE) WITH_BONUS=1 $(NAME)

$(OBJDIR)/%.o:	%.c
	@[ -d $(OBJDIR) ]
	$(CC) -c $(CFLAGS) -o $@ $< $(HEADERPATH)

$(LIBFT):
	@make -C libft

$(NAME):	$(LIBFT) $(ALL_OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(ALL_OBJS)

.PHONY:	all directories clean fclean re

#.PHONY:	all directories clean fclean re bonus

vpath %.c src
