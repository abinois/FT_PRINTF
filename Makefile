# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edillenb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 16:42:47 by edillenb          #+#    #+#              #
#    Updated: 2019/06/10 11:58:05 by edillenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT = libft/libft.a

SRC = $(addsuffix .c, \
	convert flag float_a float_b cast_arg malloc_str fill_str \
	ft_printf tools fill_float floatools color)

SRCLIBFT = $(addprefix libft/ft_, $(addsuffix .o, \
	    hexatoa lltoa llutoa memdel octatoa po putstr_fd strnew strlen strncmp\
	    strsub str_up atoi strjoinfr str_add memset strncpy strdup free_stropt\
		bitoa))

OBJ = $(SRC:.c=.o)

GREEN = \033[01;32m
BLUE = \033[01;34m
RED = \033[01;31m
YELLOW = \033[01;33m
MAGENTA = \033[35m
BLACK = \033[30m
NOCOLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ) Makefile ft_printf.h libft/Makefile libft/libft.h $(SRCLIBFT)
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 "
	@echo "🔫                                                               🔫 $(MAGENTA)"
	@echo "🔫   [ auteurs : abinois ⚡️  edillenb ]                           🔫 $(BLUE)"
	@echo "🔫                                                               🔫 "
	@echo "🔫   ._____,   ._____,     ._. .__,      ._. ._______. .______,  🔫 "
	@echo "🔫   | ._,  \  | ._,  \    |_| |   \     | | |__. .__| | .____|  🔫 "
	@echo "🔫   | |  \  | | |  \  |   ._. | |\ \    | |    | |    | |       🔫 "
	@echo "🔫   | |   | | | |   | |   | | | | \ \   | |    | |    | |__.    🔫 "
	@echo "🔫   | |__/ /  | |__/ /    | | | |  \ \  | |    | |    | .__|    🔫 "
	@echo "🔫   | .___/   |  ___ \    | | | |   \ \ | |    | |    | |       🔫 "
	@echo "🔫   | |       | |   \ \   | | | |    \ \| |    | |    | |       🔫 "
	@echo "🔫   | |       | |    \ \  | | | |     \   |    | |    | |       🔫 "
	@echo "🔫   |_|       |_|     \_\ |_| |_|      \__|    |_|    |_|       🔫 "
	@echo "🔫                                                               🔫 "
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 $(BLACK)"
	make -C libft
	@echo "$(BLUE)⚡️ COMPILATION . . . . . . . . . . . . .$(YELLOW)"
	$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ) $(SRCLIBFT)
	@ranlib $(NAME)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

clean:
	make clean -C libft
	@echo "$(BLUE)⚡️ SUPPR DES .O . . . . . . . . . .$(RED)"
	rm -f $(OBJ)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

fclean: clean
	make fclean -C libft
	@echo "$(BLUE)⚡️ SUPPR DU .A . . . . . . . .$(RED)"
	rm -f $(NAME)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(BLACK)"

re: fclean all
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫  $(BLUE)ET C'EST REPARTI ! 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 "
	@echo "$(BLUE)⚡️ RELINK . . . . . . . . . . . . . . ."
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

.PHONY: all clean fclean re