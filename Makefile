# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 15:13:41 by ludebarn          #+#    #+#              #
#    Updated: 2025/12/16 14:26:51 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

# Détection automatique du système d'exploitation
UNAME_S := $(shell uname -s)

# Lib personelle
LIBFT = ../libft

# Repertoires
OBJ_DIR_BONUS = object_bonus
OBJ_DIR = object
SRC_DIR = src
SRC_DIR_BONUS = src_bonus

# Fichiers .c
SRCS = init_struct.c fractol.c algo.c color.c mouse.c keyboard.c \
		parsing.c utils.c
SRCS_BONUS = init_struct_bonus.c fractol_bonus.c algo_bonus.c color_bonus.c \
		mouse_bonus.c keyboard_bonus.c parsing_bonus.c utils_bonus.c \
		define_palette_color_bonus.c define_palette_color2_bonus.c hsv_bonus.c \
		tui_bonus.c julia_bonus.c mandelbrot_bonus.c burningship_bonus.c \
		tricorn_bonus.c phoenix_bonus.c

# Chemins complets vers les fichiers source
SRC_FILES = $(addprefix $(SRC_DIR)/,$(SRCS))
SRC_FILES_BONUS = $(addprefix $(SRC_DIR_BONUS)/,$(SRCS_BONUS))

# Chemins vers les fichiers objets correspondants
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJS_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c,$(OBJ_DIR_BONUS)/%.o,$(SRC_FILES_BONUS))

# Configurations de bases
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Chemins d'inclusion communs
INCLUDES = -I . -I $(LIBFT)/

# Configuartion au systeme graphique
ifeq ($(UNAME_S),Linux)
# Configuration pour Linux
	MLX_DIR = minilibx-linux
	MLX_LIB = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	CFLAGS += -D LINUX=1
	OS_MSG = Linux 🐧
endif

# Ajouter le répertoire MLX aux includes
INCLUDES += -I $(MLX_DIR)

# Bibliothèques personnelles
LIBRARY_PATH = -L$(LIBFT)
LIBRARIES = -lft

# Custom
COMPILE_MSG = @printf "."

# Rules
all: $(NAME)
bonus: $(NAME_BONUS)

# Compilation de l'exécutable principal
$(NAME): $(MLX_LIB) $(OBJS)
	@echo "\n🔗 Linkage pour $(OS_MSG)..."
	@make -s -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_PATH) $(LIBRARIES) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation terminée pour la partie mandatory sous $(OS_MSG) !"

$(NAME_BONUS): $(MLX_LIB) $(OBJS_BONUS)
	@echo "\n🔗 Linkage pour $(OS_MSG)..."
	@make -s -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBRARY_PATH) $(LIBRARIES) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "✅ Compilation terminée pour les bonus sous $(OS_MSG) !"

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

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(COMPILE_MSG)

# Nettoyage des fichiers objets
clean:
	@echo "🧹 Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@make -C $(LIBFT) clean
	@make -C $(MLX_DIR) clean
	@echo "✅ Nettoyage terminé !"

# Nettoyage complet
fclean: clean
	@echo "🧹 Nettoyage complet..."
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT) fclean
	@echo "✅ Nettoyage complet terminé !"

# Recompilation complète
re: fclean all

# Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re bonus

