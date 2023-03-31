# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 01:18:20 by ttakami           #+#    #+#              #
#    Updated: 2023/03/31 12:21:02 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= ft_printf.c ft_printf_utils.c ft_uitoa_base.c ft_put_char.c
#SRCSB		=
LIBFTDIR	= libft
LIBFT		= $(addprefix $(LIBFTDIR)/, libft.a)
INC			= -Iinclude -I$(LIBFTDIR)
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#OBJSB		= $(addprefix $(OBJDIR)/, $(SRCSB:.c=.o))

#ifdef WITH_BONUS
#ALL_OBJS	= $(OBJSB)
#else
ALL_OBJS	= $(OBJS)
#endif

# color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all:	$(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@[ -d $(OBJDIR) ]
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	@make bonus --no-print-directory -sC $(LIBFTDIR)

$(NAME): $(LIBFT) $(ALL_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	ar rcs $(NAME) $(ALL_OBJS) $(LIBFT)
	@echo "$(GREEN)***   Library $(NAME) successfully compiled   ***\n$(RESET)"

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -rf $(OBJDIR)
	@make clean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@make fclean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

re:	fclean all

#bonus:
#	@$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY:	all clean fclean re

#.PHONY:	all clean fclean re bonus

vpath %.c src
