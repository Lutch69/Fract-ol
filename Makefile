# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 15:13:41 by ludebarn          #+#    #+#              #
#    Updated: 2025/12/06 16:10:11 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  FRACTOL                                     #
# **************************************************************************** #

NAME = fractol

# Détection automatique du système d'exploitation
UNAME_S := $(shell uname -s)

# Lib personelle
LIBFT = ../libft
PRINTF = ../printf

# Repertoires
OBJ_DIR = object
SRC_DIR = src

# Fichiers .c
SRCS = init_struct.c fractol.c algo.c color.c mouse.c keyboard.c parsing.c utils.c

# Chemins complets vers les fichiers source
SRC_FILES = $(addprefix $(SRC_DIR)/,$(SRCS))

# Chemins vers les fichiers objets correspondants
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Configurations de bases
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Chemins d'inclusion communs
INCLUDES = -I . -I $(LIBFT) -I $(PRINTF)/

# Configuartion au systeme graphique
ifeq ($(UNAME_S),Linux)
    # Configuration pour Linux
    MLX_DIR = minilibx-linux
    MLX_LIB = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
    CFLAGS += -D LINUX=1
    OS_MSG = Linux 🐧
endif

ifeq ($(UNAME_S),Darwin)
    # Configuration pour macOS
    MLX_DIR = minilibx_opengl_20191021
    MLX_LIB = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
    CFLAGS += -D MACOS=1
    OS_MSG = macOS 🍎
endif

# Ajouter le répertoire MLX aux includes
INCLUDES += -I $(MLX_DIR)

# Bibliothèques personnelles
LIBRARY_PATH = -L$(LIBFT) -L$(PRINTF)
LIBRARIES = -lft

# Custom
COMPILE_MSG = @printf "."

# Rules
all: $(NAME)

# Compilation de l'exécutable principal
$(NAME): $(MLX_LIB) $(OBJS)
	@echo "\n🔗 Linkage pour $(OS_MSG)..."
	@make -s -C $(LIBFT)
	@make -s -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_PATH) $(LIBRARIES) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation terminée pour $(OS_MSG) !"

# Compilation de la MiniLibX selon l'OS détecté
$(MLX_LIB):
	@echo "🔨 Compilation de la MiniLibX pour $(OS_MSG)..."
	@make -C $(MLX_DIR)
	@echo "✅ MiniLibX compilée !"

# Règle pour créer les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(COMPILE_MSG)

# Nettoyage des fichiers objets
clean:
	@echo "🧹 Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean
	@make -C $(MLX_DIR) clean
	@echo "✅ Nettoyage terminé !"

# Nettoyage complet
fclean: clean
	@echo "🧹 Nettoyage complet..."
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean
	@echo "✅ Nettoyage complet terminé !"

# Recompilation complète
re: fclean all

# Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re

