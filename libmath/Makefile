#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 01:31:26 by mwelsch           #+#    #+#              #
#    Updated: 2014/02/13 13:00:13 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

INC_DIR		= ./inc
OBJ_DIR		= ./obj
SRC_DIR		= ./src
OBJ_DEBUG_DIR = $(OBJ_DIR)/debug
OBJ_RELEASE_DIR = $(OBJ_DIR)/release

SRC			= vec3_add.c vec3_sub.c vec3_mul.c vec3_div.c vec3_scale.c \
				vec3_length.c vec3_norm.c vec3_create.c vec2_create.c
OBJ			= $(SRC:.c=.o)
UNITS		= $(patsubst %, $(SRC_DIR)/%, $(SRC))
UNITS_O		= $(patsubst %, $(OBJ_RELEASE_DIR)/%, $(OBJ))
UNITS_OD	= $(patsubst %, $(OBJ_DEBUG_DIR)/%, $(OBJ))

LIBFT_NAME	= libft
LIBFT_NAME_D= $(LIBFT_NAME)_d
LIBFT_DIR	= ../$(LIBFT_NAME)
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_RULE	= $(LIBFT_NAME).a
LIBFT_RULE_D = $(LIBFT_NAME_D).a
LIBFT_TARGET = $(LIBFT_DIR)/$(LIBFT_RULE)
LIBFT_TARGET_D= $(LIBFT_DIR)/$(LIBFT_RULE_D)

INCLUDE		=  -Iinc -I$(LIBFT_INC) -I/usr/include/X11

NAME		= libmath.a
NAME_D		= libmath_d.a

FLAGS		= -W -Wall -Werror -ansi -std=c89 -pedantic -Qunused-arguments \
				-I$(INC_DIR) -I$(LIBFT_INC)
CFLAGS		= $(FLAGS) -O3
CFLAGS_D	= $(FLAGS) -ggdb -D_DEBUG
RM			= rm -f
CC			= clang $(CFLAGS)
CC_D		= clang $(CFLAGS_D)
AR			= ar rcs

$(NAME): $(UNITS_O) $(LIBFT_TARGET)
	@echo Linking $^ into $@
	@$(AR) $@ $^

$(NAME_D): $(UNITS_OD) $(LIBFT_TARGET_D)
	@echo Linking $^ into $@
	@$(AR) $@ $^

$(LIBFT_TARGET):
	make $(LIBFT_NAME).a -C $(LIBFT_DIR)

$(LIBFT_TARGET_D):
	make $(LIBFT_NAME_D).a -C $(LIBFT_DIR)

$(OBJ_RELEASE_DIR)/%.o: src/%.c
	@echo Compiling $< into $@
	@$(CC) -c -o $@ $< $(INCLUDE)

$(OBJ_DEBUG_DIR)/%.o: src/%.c
	@echo Compiling $< into $@
	@$(CC_D) -c -o $@ $< $(INCLUDE)

all: debug release

debug: $(NAME_D)
release: $(NAME)

clean:
	@echo Removing object files
	@$(RM) $(UNITS_O)
	@$(RM) $(UNITS_OD)

fclean: clean
	@echo Removing targets
	@$(RM) $(NAME)
	@$(RM) $(NAME_D)

re: fclean all

me: all clean

.PHONY: all clean fclean re debug release
