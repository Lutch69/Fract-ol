# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 15:13:41 by ludebarn          #+#    #+#              #
#    Updated: 2025/12/01 12:06:13 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Library
LIBFT = ../libft
PRINTF = ../printf
MLX = minilibx-linux

# Directory
OBJ_DIR = object
SRC_DIR = src

# Files src mandatory
SRCS = init_struct.c fractol.c algo.c color.c mouse.c

# Objects
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))


# Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I . -I $(LIBFT) -I $(PRINTF)/ -I $(MLX)
LIBRARYPATH = -L$(LIBFT) -L$(PRINTF) -L$(MLX)
LIBRARIES = -lft -lmlx -lXext -lX11 -lm

# Custom
COMPILE_MSG = @printf "."

# Règles pour créer les .o mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(COMPILE_MSG)

# Compilation mandatory
$(NAME): $(OBJS)
	@make -s -C $(LIBFT)
	@make -s -C $(PRINTF)
	@make -s -C $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARYPATH) $(LIBRARIES) -o $(NAME)
	@echo "\n✅ Compilation mandatory terminée !"

# Règles principales
all: $(NAME)

# Cleaning
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
