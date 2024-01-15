/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_npc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:20:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/15 10:51:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_chage(t_main *var, int x, int y);

void	ft_move_npc(t_main *var)
{
	int	y;
	int	x;

	y = var->npc_y;
	x = var->npc_x;
	if (var->matrix[y + var->move_y][x] == '1'
			|| var->matrix[y + var->move_y][x] == 'C')
		var->move_y = var->move_y * -1;
	if (var->matrix[y + var->move_y][x] == 'P')
	{
		ft_printf("GAME OVER!!!");
		ft_delete_all_image(var);
	}
	ft_chage(var, x * var->size_image, (y + var->move_y) * var->size_image);
	var->matrix[var->npc_y][var->npc_x] = '0';
	var->matrix[y + var->move_y][x] = 'V';
	var->npc_y += var->move_y;
}

static void	ft_chage(t_main *var, int x, int y)
{
	mlx_delete_texture(var->s_mlx->png[ASTEROID]);
	mlx_delete_image(var->s_mlx->window,
		var->s_mlx->img[ASTEROID]);
	var->s_mlx->png[ASTEROID] = mlx_load_png(PNG_ASTEROID);
	if (!var->s_mlx->png[ASTEROID])
		ft_error("ERROR 5! Load png", var, 3);
	var->s_mlx->img[ASTEROID] = mlx_texture_to_image(var->s_mlx->window,
			var->s_mlx->png[ASTEROID]);
	if (!var->s_mlx->img[ASTEROID])
		ft_error("ERROR 6! Load img", var, 3);
	mlx_resize_image(var->s_mlx->img[ASTEROID],
		var->size_image, var->size_image);
	if ((mlx_image_to_window(var->s_mlx->window,
				var->s_mlx->img[ASTEROID], x, y)) < 0)
		ft_error("ERROR 8! Image to window", var, 3);
}
