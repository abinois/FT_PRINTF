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

SRC = $(addprefix $(SRCDIR)/, $(addsuffix .c, \
		convert flag float_a float_b cast_arg malloc_str fill_str \
		ft_printf tools fill_float floatools color))

SRCLIBFT = $(addprefix libft/ft_, $(addsuffix .o, \
	    hexatoa lltoa llutoa memdel octatoa po putstr_fd strnew strlen strncmp\
	    strsub str_up atoi strjoinfr str_add memset strncpy strdup free_stropt\
		bitoa))

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

SRCDIR = src
LIBFT = libft/libft.a
INC = -I include -I libft
CFLAGS = -Wall -Werror -Wextra
CC = gcc $(INC) $(CFLAGS)

GREEN = \033[32m
BLUE = \033[34m
RED = \033[31m
YELLOW = \033[33m
MAGENTA = \033[35m
CYAN = \033[36m
BLACK = \033[30m
UNDER = \033[4m
BLINK = \033[5m
REVERSE = \033[7m
NOCOLOR = \033[0m

NB_FILE = $(words $(SRC))
CPT = 1

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ar rc $(NAME) $(OBJ) $(SRCLIBFT)
	@ranlib $(NAME)
	@echo "$(YELLOW)            [ authors : abinois & edillenb ]$(BLUE)"
	@echo "------------------------------------------------------------- "
	@echo "  ._____,   ._____,     ._. .__,      ._. ._______. .______,  "
	@echo "  | ._,  \  | ._,  \    |_| |   \     | | |__. .__| | .____|  "
	@echo "  | |  \  | | |  \  |   ._. | |\ \    | |    | |    | |       "
	@echo "  | |   | | | |   | |   | | | | \ \   | |    | |    | |__.    "
	@echo "  | |__/ /  | |__/ /    | | | |  \ \  | |    | |    | .__|    "
	@echo "  | .___/   |  ___ \    | | | |   \ \ | |    | |    | |       "
	@echo "  | |       | |   \ \   | | | |    \ \| |    | |    | |       "
	@echo "  | |       | |    \ \  | | | |     \   |    | |    | |       "
	@echo "  |_|       |_|     \_\ |_| |_|      \__|    |_|    |_|       "
	@echo "------------------------------------------------------------- "
	@echo "                   $(BLINK)👌 $(NOCOLOR)$(GREEN)A L L   G O O D $(NOCOLOR)$(BLINK)👌 $(NOCOLOR)"

-include $(DEP)

$(SRCDIR)/%.o : $(SRCDIR)/%.c Makefile
	@echo "\033[K$(BLUE)Compilation of file$(NOCOLOR) [$(CPT) / $(NB_FILE)] : $(GREEN)$<\033[A$(NOCOLOR)"
	$(eval CPT=$(shell echo $$(($(CPT) + 1))))
	@gcc $(CFLAGS) $(INC) -MMD -MP -c $< -o $@ 

$(LIBFT) : force
	@make -C libft
force :

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "$(MAGENTA)SUPPR  $(YELLOW)OBJ $(MAGENTA): $(GREEN) OK !$(NOCOLOR)"
	@rm -f $(DEP)
	@echo "$(MAGENTA)SUPPR  $(YELLOW)DEP $(MAGENTA): $(GREEN) OK !$(NOCOLOR)"
	@echo "$(GREEN)PRINTF CLEAN : 👌 $(NOCOLOR)"

fclean: clean
	@make fclean -C libft
	@echo "$(MAGENTA)SUPPR  $(YELLOW)EXE$(MAGENTA): $(RED)$(NAME)$(NOCOLOR)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
