/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:22:24 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/09 14:31:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_chage(t_main *var, int x, int y, char *png);
static void	ft_put_count_window(t_main *var);
static void	ft_reduce_line(t_main *var, int x, int y);

void	ft_move_hero(t_main *var, int up_down, int left_rig, char *png)
{
	int		y;
	int		x;

	y = var->p->y + up_down;
	x = var->p->x + left_rig;
	if (var->matrix[y][x] != '1')
	{
		ft_reduce_line(var, x, y);
		var->p->movements++;
		ft_printf("%d\n", var->p->movements);
		ft_chage(var, x * var->size_image, y * var->size_image, png);
		ft_put_count_window(var);
		var->p->y += up_down;
		var->p->x += left_rig;
	}
}

static void	ft_chage(t_main *var, int x, int y, char *png)
{
	mlx_delete_texture(var->s_mlx->png[HERO]);
	mlx_delete_image(var->s_mlx->window,
		var->s_mlx->img[HERO]);
	var->s_mlx->png[HERO] = mlx_load_png(png);
	if (!var->s_mlx->png[HERO])
		ft_error("ERROR 5! Load png", var, 3);
	var->s_mlx->img[HERO] = mlx_texture_to_image(var->s_mlx->window,
			var->s_mlx->png[HERO]);
	if (!var->s_mlx->img[HERO])
		ft_error("ERROR 6! Load img", var, 3);
	mlx_resize_image(var->s_mlx->img[HERO], var->size_image, var->size_image);
	if ((mlx_image_to_window(var->s_mlx->window,
				var->s_mlx->img[HERO], x, y)) < 0)
		ft_error("ERROR 8! Image to window", var, 3);
}

static void	ft_put_count_window(t_main *var)
{
	char	*count;

	mlx_delete_texture(var->s_mlx->png[COUNT]);
	mlx_delete_image(var->s_mlx->window,
		var->s_mlx->img[COUNT]);
	var->s_mlx->png[COUNT] = mlx_load_png(PNG_WALL);
	if (!var->s_mlx->png[COUNT])
		ft_error("ERROR 5! Load png", var, 3);
	var->s_mlx->img[COUNT] = mlx_texture_to_image(var->s_mlx->window,
			var->s_mlx->png[COUNT]);
	if (!var->s_mlx->img[COUNT])
		ft_error("ERROR 6! Load img", var, 3);
	mlx_resize_image(var->s_mlx->img[COUNT], var->size_image, var->size_image);
	if ((mlx_image_to_window(var->s_mlx->window,
				var->s_mlx->img[COUNT], 0, 0)) < 0)
		ft_error("ERROR 8! Image to window", var, 3);
	count = ft_itoa(var->p->movements);
	mlx_put_string(var->s_mlx->window, count, 0, 0);
	free(count);
}

static void	ft_reduce_line(t_main *var, int x, int y)
{
	if (var->matrix[var->p->y][var->p->x] == 'V')
	{
		ft_printf("GAME OVER!!!");
		ft_delete_all_image(var);
	}
	if (var->matrix[y][x] == 'C')
	{
		if ((mlx_image_to_window(var->s_mlx->window, var->s_mlx->img[BACK],
					x * var->size_image, y * var->size_image)) < 0)
			ft_error("ERROR 9! Image to window", var, 3);
		var->it->collect--;
	}
	if (var->it->collect == 0)
		var->matrix[var->y_exit][var->x_exit] = 'E';
	if (var->matrix[y][x] == 'E' && var->it->collect == 0)
	{
		ft_printf("YOU WIN!!!");
		ft_delete_all_image(var);
	}
	if (var->matrix[y][x] == 'V')
	{
		ft_printf("YOU LOSE!!!");
		ft_delete_all_image(var);
	}
	var->matrix[var->p->y][var->p->x] = '0';
	var->matrix[y][x] = 'P';
}
