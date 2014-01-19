#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 01:31:26 by mwelsch           #+#    #+#              #
#    Updated: 2014/01/19 00:56:10 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

INC_DIR		= ./inc
OBJ_DIR		= ./obj
SRC_DIR		= ./src
OBJ_DEBUG_DIR = $(OBJ_DIR)/debug
OBJ_RELEASE_DIR = $(OBJ_DIR)/release

SRC			= main.c
OBJ			= $(SRC:.c=.o)
UNITS		= $(patsubst %, $(SRC_DIR)/%, $(SRC))
UNITS_O		= $(patsubst %, $(OBJ_RELEASE_DIR)/%, $(OBJ)) ../obj/release/map.o
UNITS_OD	= $(patsubst %, $(OBJ_DEBUG_DIR)/%, $(OBJ)) ../obj/debug/map.o

LIBFT_NAME	= libft
LIBFT_NAME_D= $(LIBFT_NAME)_d
LIBFT_DIR	= ../../../algo-1-001/$(LIBFT_NAME)
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_RULE	= $(LIBFT_NAME).a
LIBFT_RULE_D = $(LIBFT_NAME_D).a
LIBFT_TARGET = $(LIBFT_DIR)/$(LIBFT_RULE)
LIBFT_TARGET_D= $(LIBFT_DIR)/$(LIBFT_RULE_D)

NAME		= gnl
NAME_D		= $(NAME)_d

FLAGS		= -W -Wall -Werror -ansi -std=c89 -pedantic -Qunused-arguments \
				-I$(INC_DIR) -I$(LIBFT_INC) -I../inc
CFLAGS		= $(FLAGS) -O3
CFLAGS_D	= $(FLAGS) -ggdb -D_DEBUG

RM			= rm -f
CC			= clang $(CFLAGS)
CC_D		= clang $(CFLAGS_D)

prepare:
	@echo Preparinng release build ...
	@mkdir -p obj/release

prepare_d:
	@echo Preparing debug build ...
	@mkdir -p obj/debug

$(NAME): $(UNITS_O) $(LIBFT_TARGET)
	@echo Linking $^ into $@
	@$(CC) -o $@ $^

$(NAME_D): $(UNITS_OD) $(LIBFT_TARGET_D)
	@echo Linking $^ into $@
	@$(CC_D) -o $@ $^

../obj/release/map.o: ../src/map.c
	@echo Compiling $< into $@
	@$(CC) -c -o $@ $< -I../inc -I$(LIBFT_INC) $(LIBFT_TARGET)
../obj/debug/map.o: ../src/map.c
	@echo Compiling $< into $@
	@$(CC_D) -c -o $@ $< -I../inc -I$(LIBFT_INC) $(LIBFT_TARGET)

$(OBJ_RELEASE_DIR)/%.o: src/%.c
	@echo Compiling $< into $@
	@$(CC) -c -o $@ $< $(INCLUDE)

$(OBJ_DEBUG_DIR)/%.o: src/%.c
	@echo Compiling $< into $@
	@$(CC_D) -c -o $@ $< $(INCLUDE)

$(MAP_CREATOR):
	make $@ -C ./map_creator

$(MAP_CREATOR_D):
	make $@ -C ./map_creator

all: debug release

debug: prepare_d  $(NAME_D)
release: prepare  $(NAME)

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

.PHONY: all clean fclean re debug release prepare prepare_d