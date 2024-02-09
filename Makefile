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
	@$(MAKE) -C $(PATH_MAKE_LIB) --no-print-directory

lib_so_long:
$(LIB_SO): $(PATH_SO)/Makefile
	@$(MAKE) -C $(PATH_SO) --no-print-directory

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

$(NAME): $(LIB_SO)
	@$(CC) $(LIB_SO) $(LIBFT) $(LIB_MLX) $(INCLUDE) -o $(NAME)

libft_clean:
	@$(MAKE) -C $(PATH_MAKE_LIB) fclean --no-print-directory

so_long_fclean:
	@$(MAKE) -C $(PATH_SO) fclean --no-print-directory

so_long_bonus_fclean:
	@$(MAKE) -C $(PATH_SO_BONUS) fclean --no-print-directory

libft_re:
	@$(MAKE) -C $(PATH_MAKE_LIB) re --no-print-directory

so_long_re:
	@$(MAKE) -C $(PATH_SO) re --no-print-directory

so_long_bonus_re:
	@$(MAKE) -C $(PATH_SO_BONUS) re --no-print-directory

clean:
	@rm -rf $(OBJS)

fclean: clean libft_clean so_long_fclean so_long_bonus_fclean
	@rm -rf $(NAME)

re: fclean libft_re so_long_re so_long_bonus_re all

.PHONY: all, clean, fclean, re, libmlx
