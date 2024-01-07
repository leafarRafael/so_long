/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:33:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/07 17:10:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_size_image(t_main *var)
{
	int	size_width;
	int	size_height;

	size_width = WIDTH / var->count_c;
	size_height = HEIGHT / var->count_l;
	if (size_width < size_height)
		return (size_width);
	return (size_height);
}

void	ft_creat_texture_image(t_main *var, int png, char *type_png)
{
	var->size_image = ft_size_image(var);
	var->s_mlx->png[png] = mlx_load_png(type_png);
	if (!var->s_mlx->png[png])
		ft_error("ERROR 10! Load png", var, 3);
	var->s_mlx->img[png] = mlx_texture_to_image(var->s_mlx->window,
			var->s_mlx->png[png]);
	if (!var->s_mlx->img[png])
		ft_error("ERROR 11! Load img", var, 3);
	mlx_resize_image(var->s_mlx->img[png], var->size_image, var->size_image);
}

void	ft_init_all_image(t_main *var)
{
	ft_creat_texture_image(var, WALL, PNG_WALL);
	ft_creat_texture_image(var, HERO, PNG_HERO_UP);
	ft_creat_texture_image(var, EXIT, PNG_EXIT);
	ft_creat_texture_image(var, COLLECT, PNG_COLLECT);
	ft_creat_texture_image(var, BACK, PNG_BACK);
	ft_creat_texture_image(var, COUNT, PNG_WALL);
	ft_creat_texture_image(var, ASTEROID, PNG_ASTEROID);
}

void	ft_delete_all_image(t_main *var)
{
	mlx_delete_image(var->s_mlx->window, var->s_mlx->img[WALL]);
	mlx_delete_image(var->s_mlx->window, var->s_mlx->img[HERO]);
	mlx_delete_image(var->s_mlx->window, var->s_mlx->img[BACK]);
	mlx_delete_image(var->s_mlx->window, var->s_mlx->img[COLLECT]);
	mlx_delete_image(var->s_mlx->window, var->s_mlx->img[EXIT]);
	mlx_delete_image(var->s_mlx->window, var->s_mlx->img[COUNT]);
	mlx_delete_image(var->s_mlx->window, var->s_mlx->img[ASTEROID]);
	mlx_delete_texture(var->s_mlx->png[ASTEROID]);
	mlx_delete_texture(var->s_mlx->png[COUNT]);
	mlx_delete_texture(var->s_mlx->png[WALL]);
	mlx_delete_texture(var->s_mlx->png[HERO]);
	mlx_delete_texture(var->s_mlx->png[BACK]);
	mlx_delete_texture(var->s_mlx->png[COLLECT]);
	mlx_delete_texture(var->s_mlx->png[EXIT]);
	ft_matrix_free(var->matrix);
	mlx_terminate(var->s_mlx->window);
	exit(1);
}
