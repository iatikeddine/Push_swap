# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/14 08:41:27 by iatikedd          #+#    #+#              #
#    Updated: 2025/12/23 10:03:42 by iatikedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
BONUS   = checker
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRC     = ft_atoi.c ft_split.c helpers_2.c helpers.c main.c \
          operations_1.c operations_2.c push_swap.c inputs.c \
          push_chunk.c push_back.c

SRCB    = checker.c get_next_line.c get_next_line_utils.c apply_operations.c \
          helpers_bonus.c inputs_bonus.c operations_bonus_1.c ft_split_bonus.c \
          operations_bonus_2.c operations_bonus_3.c ft_atoi_bonus.c

OBJ     = $(SRC:.c=.o)
OBJB    = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJB)
	cc $(CFLAGS) $(OBJB) -o $(BONUS)

%.o: %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all