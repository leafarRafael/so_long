/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:47:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/15 10:39:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_parse_help(t_main *var, int x, int y)
{
	int	p_y;
	int	p_x;

	p_y = y * var->size_image;
	p_x = x * var->size_image;
	if ((mlx_image_to_window(var->s_mlx->window,
				var->s_mlx->img[BACK], p_x, p_y)) < 0)
		ft_error("ERROR 13! Image to window\n", var, 3);
	if (var->matrix[y][x] == '1')
		if ((mlx_image_to_window(var->s_mlx->window,
					var->s_mlx->img[WALL], p_x, p_y)) < 0)
			ft_error("ERROR 14! Image to window\n", var, 3);
	if (var->matrix[y][x] == 'P')
		if ((mlx_image_to_window(var->s_mlx->window,
					var->s_mlx->img[HERO], p_x, p_y)) < 0)
			ft_error("ERROR 15! Image to window\n", var, 3);
	if (var->matrix[y][x] == 'C')
		if ((mlx_image_to_window(var->s_mlx->window,
					var->s_mlx->img[COLLECT], p_x, p_y)) < 0)
			ft_error("ERROR 16! Image to window\n", var, 3);
	if (var->matrix[y][x] == 'E')
		if ((mlx_image_to_window(var->s_mlx->window,
					var->s_mlx->img[EXIT], p_x, p_y)) < 0)
			ft_error("ERROR 17! Image to window\n", var, 3);
}

void	ft_put_image_to_window(t_main *var)
{
	int	y;
	int	x;

	y = 0;
	while (var->matrix[y])
	{
		x = 0;
		while (var->matrix[y][x] != '\0')
		{
			ft_parse_help(var, x, y);
			if (var->matrix[y][x] == 'E')
			{
				var->x_exit = x;
				var->y_exit = y;
			}
			x++;
		}
		y++;
	}
}
