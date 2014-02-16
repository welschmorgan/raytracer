#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 01:31:26 by mwelsch           #+#    #+#              #
#    Updated: 2014/02/16 14:30:37 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

INC_DIR		= ./inc
OBJ_DIR		= ./obj
SRC_DIR		= ./src
OBJ_DEBUG_DIR = $(OBJ_DIR)/debug
OBJ_RELEASE_DIR = $(OBJ_DIR)/release

SRC			= main.c engine.c render.c camera.c collision.c \
				renderer.c renderer_init.c \
				sphere.c \
				scene.c \
				color_hex.c color_add.c color_sub.c color_mul.c color_div.c \
				color_scale.c color_uchar.c color_create.c
OBJ			= $(SRC:.c=.o)
UNITS		= $(patsubst %, $(SRC_DIR)/%, $(SRC))
UNITS_O		= $(patsubst %, $(OBJ_RELEASE_DIR)/%, $(OBJ))
UNITS_OD	= $(patsubst %, $(OBJ_DEBUG_DIR)/%, $(OBJ))

LIBFT_NAME	= libft
LIBFT_NAME_D= $(LIBFT_NAME)_d
LIBFT_DIR	= ./$(LIBFT_NAME)
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_RULE	= $(LIBFT_NAME).a
LIBFT_RULE_D = $(LIBFT_NAME_D).a
LIBFT_TARGET = $(LIBFT_DIR)/$(LIBFT_RULE)
LIBFT_TARGET_D= $(LIBFT_DIR)/$(LIBFT_RULE_D)

LIBMATH_NAME	= libmath
LIBMATH_NAME_D= $(LIBMATH_NAME)_d
LIBMATH_DIR	= ./$(LIBMATH_NAME)
LIBMATH_INC = $(LIBMATH_DIR)/inc
LIBMATH_RULE	= $(LIBMATH_NAME).a
LIBMATH_RULE_D = $(LIBMATH_NAME_D).a
LIBMATH_TARGET = $(LIBMATH_DIR)/$(LIBMATH_RULE)
LIBMATH_TARGET_D= $(LIBMATH_DIR)/$(LIBMATH_RULE_D)

INCLUDE		=  -Iinc -I$(LIBFT_INC) -I$(LIBMATH_INC) -I/usr/include/X11

NAME		= rtv1
NAME_D		= $(NAME)_d

FLAGS		= -Wall -Werror -Wextra -ansi -std=c89 -pedantic \
				-Qunused-arguments $(INCLUDE)
CFLAGS		= $(FLAGS) -O3
CFLAGS_D	= $(FLAGS) -ggdb -D_DEBUG
LDFLAGS		= -L/usr/X11/lib -lXext -lX11 -lmlx -lm
RM			= rm -f
CC			= clang $(CFLAGS)
CC_D		= clang $(CFLAGS_D)


all: debug release

debug: $(NAME_D)
release: $(NAME)

$(NAME): $(UNITS_O) $(LIBFT_TARGET) $(LIBMATH_TARGET)
	@printf "\r\033[KLinking $@\n"
	@$(CC) -o $@ $^ $(LDFLAGS)

$(NAME_D): $(UNITS_OD) $(LIBFT_TARGET_D) $(LIBMATH_TARGET_D)
	@printf "\r\033[KLinking $@\n"
	@$(CC_D) -o $@ $^ $(LDFLAGS)

$(LIBFT_TARGET):
	@make $(LIBFT_NAME).a -s -C $(LIBFT_DIR)

$(LIBFT_TARGET_D):
	@make $(LIBFT_NAME_D).a -s -C $(LIBFT_DIR)

$(LIBMATH_TARGET):
	@make release -s -C $(LIBMATH_DIR)

$(LIBMATH_TARGET_D):
	@make debug -s -C $(LIBMATH_DIR)

$(OBJ_RELEASE_DIR)/%.o: src/%.c
	@printf "\r\033[KCompiling $<"
	@$(CC) -c -o $@ $< $(INCLUDE)

$(OBJ_DEBUG_DIR)/%.o: src/%.c
	@printf "\r\033[KCompiling $<"
	@$(CC_D) -c -o $@ $< $(INCLUDE)

run: debug release
	./rtv1

clean:
	@echo Removing object files
	@$(RM) $(UNITS_O)
	@$(RM) $(UNITS_OD)

fclean: clean
	@echo Removing targets
	@$(RM) $(NAME)
	@$(RM) $(NAME_D)

re: fclean all

me: fclean all clean run

.PHONY: all clean fclean re debug release run
