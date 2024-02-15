/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:58:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/15 10:43:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_window(t_main *var)
{
	var->s_mlx->window = mlx_init(WIDTH, HEIGHT, "SO_LONG", true);
	if (!var->s_mlx->window)
		ft_error("ERROR 12! Load img\n", var, 3);
	var->count_c = ft_strlen(var->matrix[0]);
	var->count_l = ft_size_y(var->matrix);
	var->p->x = 0;
	var->p->y = 0;
	var->npc_x = 0;
	var->npc_y = 0;
	var->move_y = 1;
	ft_ask_for_me(var->matrix, 'V', &var->npc_y, &var->npc_x);
	ft_ask_for_me(var->matrix, 'P', &var->p->y, &var->p->x);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	ft_init_all_image(var);
	ft_put_image_to_window(var);
	mlx_key_hook(var->s_mlx->window, &ft_my_hooks, var);
	mlx_loop_hook(var->s_mlx->window, &ft_my_hook_npc, var);
	mlx_loop(var->s_mlx->window);
}
