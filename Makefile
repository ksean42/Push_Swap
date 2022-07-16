# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksean <ksean@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 22:52:26 by ksean             #+#    #+#              #
#    Updated: 2020/08/10 23:49:17 by ksean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = ./src/

SRC = $(addprefix $(PATH), validation.c operations.c \
				operations2.c push_pop.c utils.c)
PUSH_SWAP_SRC = $(addprefix $(PATH), push_swap.c solve.c utils2.c)

CHECKER_SRC = $(addprefix $(PATH), checker.c)

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
OBJ = $(SRC:.c=.o)

PUSH_SWAP_BIN = push_swap
CHECKER_BIN = checker
INC = ./include
LIB = ./libft/libft.a
LIB_PATH = ./libft/

FLAGS = -Wall -Wextra -Werror

all: $(PUSH_SWAP_BIN) $(CHECKER_BIN)

$(PUSH_SWAP_BIN): $(LIB) $(OBJ) $(PUSH_SWAP_OBJ) $(LIB_PATH)/libft.h $(LIB_PATH)*.c $(INC)/push_swap.h
		/usr/bin/gcc -g $(FLAGS) $(OBJ) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP_BIN) $(LIB)

$(CHECKER_BIN): $(LIB) $(OBJ) $(CHECKER_OBJ) $(LIB_PATH)/libft.h $(LIB_PATH)*.c $(INC)/push_swap.h
		/usr/bin/gcc -g $(FLAGS) $(CHECKER_OBJ) $(OBJ) -o $(CHECKER_BIN) $(LIB) -I $(LIB_PATH)

$(PUSH_SWAP_OBJ): %.o: %.c
		/usr/bin/gcc -g $(FLAGS) -I $(INC) -I $(LIB_PATH) -o $@ -c $^

$(CHECKER_OBJ): %.o: %.c
		/usr/bin/gcc -g $(FLAGS) -I $(INC) -I $(LIB_PATH) -o $@ -c $^

$(OBJ): %.o: %.c
		/usr/bin/gcc -g $(FLAGS) -I $(INC) -I $(LIB_PATH) -o $@ -c $^

$(LIB):
		/usr/bin/make -C $(LIB_PATH)

clean:
		/bin/rm -rf $(PUSH_SWAP_OBJ) $(CHECKER_OBJ) $(OBJ)
		/usr/bin/make clean -C $(LIB_PATH)

fclean: clean
		/bin/rm -rf $(PUSH_SWAP_BIN) $(CHECKER_BIN)
		/usr/bin/make fclean -C $(LIB_PATH)

re: fclean all
