# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edillenb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 16:42:47 by edillenb          #+#    #+#              #
#    Updated: 2019/05/29 17:44:35 by abinois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT = libft/libft.a

SRC = $(addsuffix .c, \
	buffer convert flag float_a float_b cast_arg malloc_str fill_str \
	ft_printf tools fill_float floatools)

SRCLIBFT = $(addprefix libft/ft_, $(addsuffix .o, \
	    hexatoa lltoa llutoa memdel octatoa pow putstr strnew strlen \
	    strsub str_up atoi strjoinfr str_add putnstr memset strncpy))

OBJ = $(SRC:.c=.o)

GREEN = \033[01;32m 
BLUE = \033[01;34m 
RED = \033[01;31m 
YELLOW = \033[01;33m 
NOCOLOR = \033[01;30m 

all: $(NAME)

$(NAME): $(OBJ) Makefile ft_printf.h
	make -C libft
	@ar xv $(LIBFT) $(SRCLIBFT)
	@echo "$(BLUE)COMPILATION . . . . . . . . . . . . .$(YELLOW)"
	$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ) $(SRCLIBFT)
	@ranlib $(NAME)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

clean:
	@echo "$(BLUE)SUPPRESSION DES .O . . . . . . . . . .$(RED)"
	make clean -C libft
	rm -f $(OBJ)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

fclean: clean
	@echo "$(BLUE)SUPPRESSION DE LA LIB . . . . . . . .$(RED)"
	make fclean -C libft
	rm -f $(NAME)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

re: fclean all
	@echo "$(BLUE)RELINK . . . . . . . . . . . . . . ."
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

.PHONY: all clean fclean re
