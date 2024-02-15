/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_npc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:20:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/15 10:43:12 by rbutzke          ###   ########.fr       */
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
		ft_printf("GAME OVER!!!\n");
		ft_delete_all_image(var);
	}
	ft_chage(var, x * var->size_image, (y + var->move_y) * var->size_image);
	var->matrix[var->npc_y][var->npc_x] = '0';
	var->matrix[y + var->move_y][x] = 'V';
	var->npc_y += var->move_y;
}

static void	ft_chage(t_main *var, int x, int y)
{
	var->s_mlx->img[ASTEROID]->instances[0].x = x;
	var->s_mlx->img[ASTEROID]->instances[0].y = y;
}
