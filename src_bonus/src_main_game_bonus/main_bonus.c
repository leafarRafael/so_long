/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:28:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/07 16:59:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_ask_for_me(char	**matrix, char c, int *my_y, int *my_x)
{
	int	y;
	int	x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == c)
			{
				*my_y = y;
				*my_x = x;
				break ;
			}
			x++;
		}
		if (matrix[y][x] == c)
			break ;
		y++;
	}
}

void	ft_error(char *error, t_main *var, int type)
{
	if (type == 1)
	{
		ft_printf("%s", error);
		exit (1);
	}
	if (type == 2)
	{
		ft_matrix_free(var->v_matrix);
		ft_matrix_free(var->matrix);
		ft_printf("%s", error);
		exit (1);
	}
	if (type == 3)
	{
		ft_matrix_free(var->v_matrix);
		ft_matrix_free(var->matrix);
		ft_printf(mlx_strerror(mlx_errno));
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	t_main	*var;
	t_valid	*v;

	var = ft_init_main();
	var->it = ft_init_itens();
	v = ft_init_valid();
	var->s_mlx = ft_init_mlx();
	var->p = ft_init_player();
	var->archive_ber = ft_validate_parameter(var, argc, argv);
	ft_ber_cpy_to_matrix(var, argc, argv);
	ft_valid_matrix(var, v);
	ft_matrix_free(var->v_matrix);
	ft_put_window(var);
	ft_delete_all_image(var);
	return (0);
}
