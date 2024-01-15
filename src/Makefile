NAME = so_long.a

FILES = src_creating_matrix/ber_to_matrix.c src_image_texture/image_texture.c src_mlx/window.c\
	src_validation_matrix/valid.c src_hero/hero_move.c src_initializing_structures/init_struct.c src_parse/parse.c\
	src_validation_matrix/valid_map_helper_1.c src_hooks/my_hooks.c src_main_game/main.c src_validation_argument/valid_arg.c\
	src_validation_matrix/valid_map_helper_2.c

NUM_FILES	:= $(words $(FILES))

O_FILE_PATH := /o_file
OBJS = ./objs
INCLUDES = -I /include
O_FILE = $(FILES:%.c=$(OBJS)/%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
O_FLAGS = -c

all : $(NAME)

$(NAME): $(O_FILE)

$(OBJS)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@ar -rc $(NAME) $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@echo "[$(shell echo $$(($(COUNT) * 100 / $(NUM_FILES))))%] Progress SRC_SO_LONG"

clean:
	rm -Rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONI: all clean fclean re bonus
