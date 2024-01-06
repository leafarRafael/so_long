NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
CC		:= cc
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/lib_get_print/libft.a
LIB_SO	:= ./src/so_long.a
PATH_SO := ./src
PATH_MAKE_LIB:= ./lib/lib_get_print
INCLUDE	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx $(NAME)

$(NAME):$(LIBFT)

libft:
$(LIBFT): $(PATH_MAKE_LIB)/Makefile
	$(MAKE) -C $(PATH_MAKE_LIB)

lib_so:
$(LIB_SO): $(PATH_SO)/Makefile
	$(MAKE) -C $(PATH_SO)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIB_SO)
	$(CC) $(LIB_SO) $(LIBFT) $(LIBS) $(INCLUDE) -o $(NAME)

libft_clean:
	$(MAKE) -C $(PATH_MAKE_LIB) fclean

so_long_fclen:
	$(MAKE) -C $(PATH_SO) fclean

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean libft_clean so_long_fclen
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx