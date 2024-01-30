NAME = so_long_bonus.a

FILES = src_creating_matrix_bonus/ber_to_matrix_bonus.c src_hero_bonus/hero_move_bonus.c src_hooks_bonus/my_hooks_bonus.c\
	src_image_texture_bonus/image_texture_bonus.c src_initializing_structures_bonus/init_struct_bonus.c\
	src_main_game_bonus/main_bonus.c src_mlx_bonus/window_bonus.c src_parse_bonus/parse_bonus.c\
	src_validation_argument_bonus/valid_arg_bonus.c src_validation_matrix_bonus/valid_bonus.c\
	src_validation_matrix_bonus/valid_map_helper_bonus_1.c src_validation_matrix_bonus/valid_map_helper_bonus_2.c\
	src_move_npc/move_npc.c

NUM_FILES	:= $(words $(FILES))

O_FILE_PATH := /o_file_bonus
OBJS = ./objs_bonus
INCLUDES = -I ../include_bonus
O_FILE = $(FILES:%.c=$(OBJS)/%.o)
CC = cc
CFLAGS = #-Wall -Werror -Wextra -Ofast
O_FLAGS = -c

all : $(NAME)

$(NAME): $(O_FILE)

$(OBJS)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@ar -rc $(NAME) $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@echo "[$(shell echo $$(($(COUNT) * 100 / $(NUM_FILES))))%] Progress SRC_BONUS_SO_LONG"

clean:
	rm -Rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONI: all clean fclean re bonus
