/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:20:56 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/15 10:52:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_my_hooks(mlx_key_data_t keyd, void *param)
{
	t_main	*var;

	var = (t_main *) param;
	if (keyd.key == MLX_KEY_ESCAPE && keyd.action == MLX_RELEASE)
	{
		ft_printf("You chose well to give up ahahah (evil laugh)!");
		ft_delete_all_image(var);
	}
	if (keyd.key == MLX_KEY_W)
		ft_move_hero(var, -1, 0, PNG_HERO_UP);
	if (keyd.key == MLX_KEY_A)
		ft_move_hero(var, 0, -1, PNG_HERO_LEFT);
	if (keyd.key == MLX_KEY_D)
		ft_move_hero(var, 0, +1, PNG_HERO_RIGTH);
	if (keyd.key == MLX_KEY_S)
		ft_move_hero(var, +1, 0, PNG_HERO_DOWN);
}

void	ft_my_hook_npc(void	*param)
{
	t_main	*var;
	double	move;

	var = (t_main *) param;
	move = (int) mlx_get_time() % 2;
	if (move != 0)
		ft_move_npc(var);
}
