/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:10:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/15 12:51:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/lib_get_print/includes/get_next_line.h"
# include "../lib/lib_get_print/includes/ft_printf.h"
# include "../lib/lib_get_print/includes/libft.h"

# define WIDTH 2048
# define HEIGHT 1024
# define UP 'W'
# define DOWN 'S'
# define LEFT 'A'
# define RIGHT 'D'
# define PNG_WALL "./image_png/tijolo.png"
# define PNG_HERO_UP "./image_png/arplaine_up.png"
# define PNG_HERO_DOWN "./image_png/arplaine_down.png"
# define PNG_HERO_LEFT "./image_png/arplaine_left.png"
# define PNG_HERO_RIGTH "./image_png/arplaine_right.png"
# define PNG_BACK "./image_png/nigth.png"
# define PNG_COLLECT "./image_png/star.png"
# define PNG_EXIT "./image_png/exit.png"
# define PNG_ASTEROID "./image_png/asteroid.png"

typedef enum e_type
{
	WALL = 0,
	EXIT,
	HERO,
	BACK,
	COLLECT,
	COUNT,
	ASTEROID
}		t_types;

typedef struct s_valid
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;
}				t_valid;

typedef struct s_itens
{
	int		hero;
	int		collect;
	int		exit;
	int		v;
}			t_itens;

typedef struct s_map
{
	int				is_wrong;
	int				s_y;
	int				s_x;
	mlx_t			*window;
	mlx_image_t		*img[7];
	mlx_texture_t	*png[7];
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	movements;
}			t_player;

typedef struct s_main
{
	t_player	*p;
	t_map		*s_mlx;
	t_itens		*it;
	int			i;
	int			n;
	int			count_l;
	int			count_c;
	int			p_x;
	int			p_y;
	int			x_exit;
	int			y_exit;
	int			npc_x;
	int			npc_y;
	int			move_y;
	int			size;
	int			size_image;
	int			fd;
	int			read_buffer;
	char		**matrix;
	char		**v_matrix;
	char		*archive_ber;
	char		*temp;
	char		buffer;
	int			frame;
	int			frame_update;
}				t_main;

/*
	folder: src_initializing_structures
	file:	init_struct.c
*/
t_player	*ft_init_player(void);
t_main		*ft_init_main(void);
t_valid		*ft_init_valid(void);
t_itens		*ft_init_itens(void);
t_map		*ft_init_mlx(void);

/* 
	folder: src_creanting_matrix
	file:	ber_to_matrix.c
*/
void		ft_size_ber(t_main	*var, int argc, char *argv[]);
void		ft_cpy_arrey_ber(t_main *var, int argc, char **argv);
void		ft_ber_cpy_to_matrix(t_main *var, int argc, char **argv);
void		ft_matrix_free(char	**matrix);

/*
	folder: src_move_npc
	file:	move_npc.c
*/
void		ft_move_npc(t_main *var);
/*
	folder: src_hero
	file:	hero_move.c
*/
void		ft_move_hero(t_main *var, int up_down, int left_rig, char *png);

/*
	folder: src_hooks
	file:	my_hook.c
*/
void		ft_my_hooks(mlx_key_data_t keyd, void *param);
void		ft_my_hook_npc(void	*param);

/*
	folder: src_image_texture
	file: image_texture.c
*/
void		ft_creat_texture_image(t_main *var, int png, char *type_png);
void		ft_init_all_image(t_main *var);
void		ft_delete_all_image(t_main *var);
int			ft_size_image(t_main *var);

/*
	folder: src_main_game
	file:	main.c
*/
void		ft_ask_for_me(char	**matrix, char c, int *my_y, int *my_x);
void		ft_error(char *error, t_main *var, int type);
int			main(int argc, char *argv[]);
/*
	folder: src_mlx
	file:	window.c
*/
void		ft_put_window(t_main *var);
/*
	folder: src_parse
	file:	parse.c
*/
void		ft_put_image_to_window(t_main *var);

/*
	folder: src_validation_argument
	file:	valid_arg.c
*/
char		*ft_validate_parameter(t_main *var, int argc, char *argv[]);

/*
	folder: src_validation_matrix
	file:	valid_map_helper_1.c valid_map_helper_2.c valid.c
*/
int			ft_is_composition(char c);
int			ft_size_y(char	**matrix);
int			ft_valid_regular_line(char	**matrix, t_valid *v);
int			ft_valid_itens(t_main *var, t_valid *v, char **matrix);
int			ft_flood_fill(char **matrix, t_valid *v);
int			ft_surrounded_by_walls(char	**matrix, t_valid *v);
int			ft_valid_composition(char **matrix, t_valid *v, int (*f)(char));
void		ft_valid_matrix(t_main	*var, t_valid	*v);

#endif
