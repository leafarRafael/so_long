NAME			:= so_long
CFLAGS			:= -Wextra -Wall -Werror
CC				:= cc
LIBMLX			:= ./lib/MLX42
LIBFT			:= ./lib/lib_get_print/libft.a
LIB_SO			:= ./src/so_long.a
PATH_SO			:= ./src
LIB_SO_BONUS	:= ./src_bonus/so_long_bonus.a
PATH_SO_BONUS 	:= ./src_bonus
PATH_MAKE_LIB	:= ./lib/lib_get_print
INCLUDE			:= -I ./include -I $(LIBMLX)/include
INCLUDE_BONUS	:= -I ./include_bonus -I $(LIBMLX)/include
LIB_MLX			:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx $(NAME)

bonus: LIB_SO	:= $(LIB_SO_BONUS)
bonus: PATH_SO	:= $(PATH_SO_BONUS)
bonus: INCLUDE	:= $(INCLUDE_BONUS)
bonus: all

$(NAME):$(LIBFT)

libft:
$(LIBFT): $(PATH_MAKE_LIB)/Makefile
	$(MAKE) -C $(PATH_MAKE_LIB)

lib_so_long:
$(LIB_SO): $(PATH_SO)/Makefile
	$(MAKE) -C $(PATH_SO)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIB_SO)
	$(CC) $(LIB_SO) $(LIBFT) $(LIB_MLX) $(INCLUDE) -o $(NAME)

libft_clean:
	$(MAKE) -C $(PATH_MAKE_LIB) fclean

so_long_fclean:
	$(MAKE) -C $(PATH_SO) fclean

so_long_bonus_fclean:
	$(MAKE) -C $(PATH_SO_BONUS) fclean

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean libft_clean so_long_fclean so_long_bonus_fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx