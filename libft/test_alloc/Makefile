NAME = allocs
NAME_D = $(NAME)_d
UNITS = main.c

OBJ_DIR = ./obj
SRC_DIR = ./src
INC_DIR = ./inc

OBJ_DIR_D = $(OBJ_DIR)/debug
OBJ_DIR_R = $(OBJ_DIR)/release

SRCS = $(patsubst %, $(SRC_DIR)/%, $(UNITS))
OBJS = $(patsubst %, $(OBJ_DIR_R)/%, $(UNITS:.c=.o))
OBJS_D = $(patsubst %, $(OBJ_DIR_D)/%, $(UNITS:.c=.o))

CFLAGS = -O3
CFLAGS_D = -ggdb -D_DEBUG

all: $(NAME) $(NAME_D)

$(NAME): $(OBJS)
	@clang -o $@ $^ ../libft_d.a $(CFLAGS)

$(NAME_D): $(OBJS_D)
	@clang -o $@ $^ ../libft_d.a $(CFLAGS_D)

$(OBJ_DIR_R)/%.o: $(SRC_DIR)/%.c
	@clang -c -o $@ $< -I../inc -I$(INC_DIR) $(CFLAGS)

$(OBJ_DIR_D)/%.o: $(SRC_DIR)/%.c
	@clang -c -o $@ $< -I../inc -I$(INC_DIR) $(CFLAGS_D)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_D)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_D)

re: fclean all

.PHONY: re clean fclean all